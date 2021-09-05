#ifndef PROJ_2_WORKER_STATS_H
#define PROJ_2_WORKER_STATS_H

#include <string>
class Worker_Stats {
 private:
  std::string disiese_id;
  int zero_twenty;
  int twentyOne_forty;
  int fortyOne_sixty;
  int sixty_plus;
 public:
  //==Constructor==//
  Worker_Stats(const std::string &disieseId);
  //==Getters==//
  const std::string &get_disiese_id() const;
  int get_zero_twenty() const;
  int get_twentyOne_forty() const;
  int get_fortyOne_sixty() const;
  int get_sixty_plus() const;
  //==Mutators==//
  void increase_zero_twenty();
  void increase_twentyOne_fort();
  void increase_fortyOne_sixty();
  void increase_sixty_plus();
};

#endif //PROJ_2_WORKER_STATS_H
