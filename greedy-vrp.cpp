#include "greedy-vrp.h"

GreedyVrp::GreedyVrp(std::vector<std::vector<int>> distanceMatrix, int nClients, int nVehicles) {
  distanceMatrix_ = distanceMatrix;
  nClients_ = nClients;
  nVehicles_ = nVehicles;
  vehicles_.resize(nVehicles_);
  for (int i = 0; i < nVehicles_; i++) {
    vehicles_[i].tour.push_back(0);
  }
  for (int i = 0; i <= nClients; i++) {
    nodes_.insert(i);
  }
}

int GreedyVrp::getClosestNode(int carIndex){
  int minDistance = INT_MAX;
  int bestNodeIndex;

  for (int nodeIndex = 1; nodeIndex <= nClients_; nodeIndex++) {
    if (nodes_.count(nodeIndex)) {
      int currentIndex = vehicles_[carIndex].tour.size() - 1;
      int tmpDistance = distanceMatrix_[vehicles_[carIndex].tour[currentIndex]][nodeIndex];
      if (tmpDistance < minDistance) {
        minDistance = tmpDistance;
        bestNodeIndex = nodeIndex;
      }
    }
  }
  return bestNodeIndex;
}

std::vector<std::vector<int>> GreedyVrp::Solve() {
  std::vector<std::vector<int>> solution;
  int carIndex = 0;

  while (nodes_.size() != 1) {
    // int minDistance = INT_MAX;
    // bool isDeposit = true;
    // int bestNodeIndex;
    int currentIndex = vehicles_[carIndex].tour.size() - 1;

    // for (int nodeIndex = 1; nodeIndex <= nClients_; nodeIndex++) {
    //   if (nodes_.count(nodeIndex)) {
    //     int tmpDistance = distanceMatrix_[vehicles_[carIndex].tour[currentIndex]][nodeIndex];
    //     if (tmpDistance < minDistance) {
    //       minDistance = tmpDistance;
    //       isDeposit = false;
    //       bestNodeIndex = nodeIndex;
    //     }
    //   }
    // }
    int bestNodeIndex = getClosestNode(carIndex);

    //if (!isDeposit) {
      vehicles_[carIndex].tour.push_back(bestNodeIndex);
      nodes_.erase(bestNodeIndex);
      carIndex = (carIndex + 1) % nVehicles_;
    //}
  }

  for (int i = 0; i < nVehicles_; i++) {
    vehicles_[i].tour.push_back(0);
    solution.push_back(vehicles_[i].tour);
  }

  return solution;
}