#ifndef SERVER_QUERY_HANDLER_H
#define SERVER_QUERY_HANDLER_H

#include "../../Tokenizer/Tokenizer.h"
#include "../../Shared_Data/Shared_Data.h"
#include "../../Worker_Socket_List/Worker_Socket_List.h"

class Query_Handler {
 protected:
  Tokenizer tokenizer;
  virtual bool validate_parameters(Generic_List<std::string>* tokenized_query)=0;

  virtual std::string reconstruct_message(Generic_List<std::string>* tokenized_query){
    std::string message=(*tokenized_query)[0];
    for(int i =1;i<tokenized_query->get_num_of_nodes();i++)
      message+=" "+(*tokenized_query)[i];
    return message;
  }

  virtual int send_to_all_workers(Generic_List<std::string> *tokenized_command, Worker_Socket_List *workers_sockets) {
    std::string message = reconstruct_message(tokenized_command);
    workers_sockets->send_message_to_all_workers(message);
  }

  virtual Worker_Socket_List* generate_worker_sockets(){
    Worker_Socket_List* worker_sockets = new Worker_Socket_List();
    for(int i =0;i<worker_ports.get_num_of_nodes();i++)
      worker_sockets->insert_node({worker_ports[i],workers_ip});
    return worker_sockets;
  }

  virtual std::string forward_command_to_all_workers(Generic_List<std::string>* tokenized_command){

    int waiting_for_answers = worker_ports.get_num_of_nodes();
    Worker_Socket_List* workers_sockets = generate_worker_sockets();
    workers_sockets->connect_to_workers();
    send_to_all_workers(tokenized_command, workers_sockets);
    std::string answer;

    while (waiting_for_answers){

      fd_set set;
      int max_fd = workers_sockets->get_max_fd();
      workers_sockets->setup_fd_set(&set);
      select(max_fd+1,&set,NULL,NULL,NULL);



      for(int i=0;i<workers_sockets->get_num_of_nodes();i++){
        if(workers_sockets->get_by_ref(i)->has_answered(&set)){
          std::string message = workers_sockets->get_by_ref(i)->read_answer();
          if(message!="None")
            answer+=message;
          waiting_for_answers--;
        }
      }
    }
    workers_sockets->close_descriptors();
    delete workers_sockets;
    return answer;
  }

 public:
  virtual std::string Execute_Command(Generic_List<std::string>* tokenized_command){
    if(!validate_parameters(tokenized_command))
      return "Validation Error";

    return forward_command_to_all_workers(tokenized_command);
  }

};

#endif //SERVER_QUERY_HANDLER_H

