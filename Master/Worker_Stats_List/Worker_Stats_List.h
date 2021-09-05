#ifndef PROJ_2_WORKER_STATS_LIST_H
#define PROJ_2_WORKER_STATS_LIST_H

#include "../Generic_List/Generic_List.h"
#include "../Worker_Stats/Worker_Stats.h"

class Worker_Stats_List: public Generic_List<Worker_Stats>{
 public:
  //==API==//
  bool is_disease_in_list(const std::string disease);
  Worker_Stats* get_stat_block(const std::string diease);

};

#endif //PROJ_2_WORKER_STATS_LIST_H
