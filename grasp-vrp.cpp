#include "grasp-vrp.h"

GraspVrp::GraspVrp(std::vector<std::vector<int>> distanceMatrix, int nClients, int nVehicles){
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

int GraspVrp::getClosestNode(int carIndex){
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

int GraspVrp::selectFromRCL(int carIndex) {
  std::vector<int> rcl;
  srand (time(NULL));
  int nodesSize =  nodes_.size() - 1;
  for (int i = 0; i < 5 && i <nodesSize ; i++) {
    int closestNode = getClosestNode(carIndex);
    rcl.push_back(closestNode);
    nodes_.erase(closestNode);
  }
  int randIndex = rand() % rcl.size();
  int returnResult = rcl[randIndex];
  for (int i = 0; i < rcl.size(); i++) {
    if (i != randIndex) {
      nodes_.insert(rcl[i]);
    }
  }
  return returnResult;
}
 

std::vector<std::vector<int>> GraspVrp::Solve(){
  std::vector<std::vector<int>> solution;
  int carIndex = 0;

  while (nodes_.size() != 1) {
    int currentIndex = vehicles_[carIndex].tour.size() - 1;
    int bestNodeIndex = selectFromRCL(carIndex);

    vehicles_[carIndex].tour.push_back(bestNodeIndex);
    nodes_.erase(bestNodeIndex);
    carIndex = (carIndex + 1) % nVehicles_;
  }

  for (int i = 0; i < nVehicles_; i++) {
    vehicles_[i].tour.push_back(0);
    solution.push_back(vehicles_[i].tour);
  }

  return solution;
}