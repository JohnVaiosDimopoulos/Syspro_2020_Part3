#include "Worker_Command_Reader.h"
#include "../Worker_Command_Handler/Worker_Disease_Frequency/Worker_Disease_Frequency.h"
#include "../Worker_Command_Handler/Worker_Num_Patient_Admissions/Worker_Num_Patient_Admissions.h"
#include "../Worker_Command_Handler/Worker_Num_Patient_Discharges/Worker_Num_Patient_Discharges.h"
#include "../Worker_Command_Handler/Worker_Search_Patient_Record/Worker_Search_Patient_Record.h"
#include "../Worker_Command_Handler/Worker_TopK_Age/Worker_TopK_Age.h"
#include <unistd.h>



void Worker_Command_Reader::read_command(System_Data *data, Query_Socket *socket) {

    std::string command = socket->read_from_socket();
    std::cout<<"Worker: "<<getpid()<<" read "<<command<<std::endl;
    Generic_List<std::string> tokenized_command = tokenizer.tokenize_command(command);

    if(tokenized_command.first==NULL)
      return;

    if(tokenized_command[0] == "/diseaseFrequency"){
      Worker_Disease_Frequency worker_disease_frequency;
      worker_disease_frequency.execute_command(data, &tokenized_command, socket);
    }

    else if(tokenized_command[0] == "/topk-AgeRanges"){
      Worker_TopK_Age worker_topK_age;
      worker_topK_age.execute_command(data, &tokenized_command, socket);
    }

    else if(tokenized_command[0] == "/searchPatientRecord"){
      Worker_Search_Patient_Record worker_search_patient_record;
      worker_search_patient_record.execute_command(data, &tokenized_command, socket);
    }

    else if(tokenized_command[0] == "/numPatientAdmissions"){
      Worker_Num_Patient_Admissions worker_num_patient_admissions;
      worker_num_patient_admissions.execute_command(data, &tokenized_command, socket);
    }

    else if(tokenized_command[0] == "/numPatientDischarges"){
      Worker_Num_Patient_Discharges worker_num_patient_discharges;
      worker_num_patient_discharges.execute_command(data, &tokenized_command, socket);
    }



}



