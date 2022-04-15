#ifndef VEHICLE_
#define VEHICLE_

#include <vector>

class Node {
 public:
  int indx;
  bool visited;
};

class Car {
 public:
  std::vector<Node> tour;
  void addNode(Node*, double**);
};

#endif