#ifndef GRASP_VRP_
#define GRASP_VRP_

#include <vector>
#include <set>
#include <climits>
#include <cstdlib>
#include <ctime>
#include "vehicle.h"

class GraspVrp {
 public:
  GraspVrp(std::vector<std::vector<int>> distanceMatrix, int nClients, int nVehicles);
  std::vector<std::vector<int>> Solve();
  int getClosestNode(int carIndex);
  int selectFromRCL(int carIndex);
 private:
  std::vector<std::vector<int>> distanceMatrix_;
  int nClients_, nVehicles_;
  std::set<int> nodes_;
  std::vector<Car> vehicles_;
};

#endif