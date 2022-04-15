#include "file-loader.h"
#include "greedy-vrp.h"
#include "grasp-vrp.h"

void printMatrix(std::vector<std::vector<int>>& distanceMatrix) {
  for (int i = 0; i < distanceMatrix.size(); i++) {
    for (int j = 0; j < distanceMatrix.size(); j++) {
      std::cout << distanceMatrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int routeDistance(std::vector<int>& route, std::vector<std::vector<int>>& distanceMatrix) {
  int distance = 0;
  for ( int i = 0; i+1 < route.size(); i++) {
    distance += distanceMatrix[route[i]][route[i + 1]];
  }
  return distance;
}

int tourDistance(std::vector<std::vector<int>>& tour, std::vector<std::vector<int>>& distanceMatrix) {
  int distance = 0;

  for (int i = 0; i < tour.size(); i++) {
    distance += routeDistance(tour[i], distanceMatrix);
  }
  return distance;
}

void printSolution(std::vector<std::vector<int>>& solution, std::vector<std::vector<int>>& distanceMatrix) {
  for (int i = 0; i < solution.size(); i++) {
    std::cout << "  Ruta " << i << ":(coste: " << routeDistance(solution[i], distanceMatrix) << ")" << "\n";
    for (int j = 0; j < solution[i].size(); j++) {
      std::cout << "  " << solution[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "  Tour distance: " << tourDistance(solution, distanceMatrix) << "\n";
}

int main(int argc, char* argv[]) {
  std::string filename = "I40j_2m_S1_1.txt";
  if (argc == 2) {
    filename = argv[1];
  }
  int nClients = 0, nVehicles = 0;
  std::vector<std::vector<int>> distanceMatrix;
  loadFromFile(filename, distanceMatrix, nClients, nVehicles);
  // printMatrix(distanceMatrix);
  // std::cout << nClients << " " << nVehicles << "\n";
  GreedyVrp greedy(distanceMatrix, nClients, nVehicles);
  GraspVrp grasp(distanceMatrix, nClients, nVehicles);
  std::vector<std::vector<int>> greedySolution = greedy.Solve();
  std::vector<std::vector<int>> graspSolution = grasp.Solve();
  std::cout << "Greedy\n";
  printSolution(greedySolution, distanceMatrix);
  std::cout << "Grasp\n";
  printSolution(graspSolution, distanceMatrix);
}

