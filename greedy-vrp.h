#ifndef GREEDY_VRP_
#define GREEDY_VRP_

#include <vector>
#include <set>
#include <climits>
#include "vehicle.h"

class GreedyVrp {
 public:
  GreedyVrp(std::vector<std::vector<int>> distanceMatrix, int nClients, int nVehicles);
  std::vector<std::vector<int>> Solve();
  int getClosestNode(int carIndex);
 private:
  std::vector<std::vector<int>> distanceMatrix_;
  int nClients_, nVehicles_;
  std::set<int> nodes_;
  std::vector<Car> vehicles_;
};

#endif