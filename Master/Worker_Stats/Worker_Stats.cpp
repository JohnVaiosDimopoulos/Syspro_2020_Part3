#include "Worker_Stats.h"


//==Constructor==//

Worker_Stats::Worker_Stats(const std::string &disieseId) : disiese_id(disieseId),zero_twenty(0),twentyOne_forty(0),fortyOne_sixty(0),sixty_plus(0) {}

//==Getters==//
const std::string &Worker_Stats::get_disiese_id() const {
  return disiese_id;
}

int Worker_Stats::get_zero_twenty() const {
  return zero_twenty;
}

int Worker_Stats::get_twentyOne_forty() const {
  return twentyOne_forty;
}

int Worker_Stats::get_fortyOne_sixty() const {
  return fortyOne_sixty;
}

int Worker_Stats::get_sixty_plus() const {
  return sixty_plus;
}

//==Muttators==//
void Worker_Stats::increase_zero_twenty() {
  this->zero_twenty++;
}

void Worker_Stats::increase_twentyOne_fort() {
  this->twentyOne_forty++;
}

void Worker_Stats::increase_fortyOne_sixty() {
  this->fortyOne_sixty++;
}

void Worker_Stats::increase_sixty_plus() {
  this->sixty_plus++;
}


