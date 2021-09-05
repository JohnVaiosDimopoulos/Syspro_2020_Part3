#include "Query_Executor.h"
#include "../Shared_Data/Shared_Data.h"
#include "Query_Handler/Disease_Frequency/Disease_Frequency.h"
#include "Query_Handler/Num_Patient_Admissions/Num_Patient_Admissions.h"
#include "Query_Handler/Num_Patient_Discharges/Num_Patient_Discharges.h"
#include "Query_Handler/Search_Patient_Record/Search_Patient_Record.h"
#include "Query_Handler/Topk_Age/Topk_Age.h"
#include "unistd.h"

void Query_Executor::Read_query_and_get_results(int fd) {

  std::string query = io_handler.read_from_socket(fd);
  std::string answer;
  Generic_List<std::string> tokenized_query = tokenizer.tokenize_command(query);

  if(tokenized_query.first == NULL)
    return;

  if(tokenized_query[0]=="/diseaseFrequency"){
    Disease_Frequency disease_frequency;
    answer = disease_frequency.Execute_Command(&tokenized_query);
  }

  else if(tokenized_query[0] =="/topk-AgeRanges"){
    Topk_Age topk_age;
    answer = topk_age.Execute_Command(&tokenized_query);
  }

  else if(tokenized_query[0] =="/searchPatientRecord"){
    Search_Patient_Record search_patient_record;
    answer = search_patient_record.Execute_Command(&tokenized_query);
  }

  else if(tokenized_query[0]=="/numPatientAdmissions"){
    Num_Patient_Admissions num_patient_admissions;
    answer = num_patient_admissions.Execute_Command(&tokenized_query);
  }

  else if(tokenized_query[0] =="/numPatientDischarges"){
    Num_Patient_Discharges num_patient_discharges;
    answer = num_patient_discharges.Execute_Command(&tokenized_query);
  }
  else
    io_handler.write_in_socket(fd,"Error: Unknown query");

  mutexes_and_cond.write_in_stdout.lock();
  std::cout<<query<<": "<<answer<<std::endl;
  mutexes_and_cond.write_in_stdout.unlock();
  io_handler.write_in_socket(fd,answer.c_str());
  close(fd);

}
