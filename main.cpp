#include "file-loader.h"

void print(std::vector<std::vector<int>>& distanceMatrix) {
  for (int i = 0; i < distanceMatrix.size(); i++) {
    for (int j = 0; j < distanceMatrix.size(); j++) {
      std::cout << distanceMatrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  int nClients = 0, nVehicles = 0;
  std::vector<std::vector<int>> distanceMatrix;
  loadFromFile("I40j_2m_S1_1.txt", distanceMatrix, nClients, nVehicles);
  print(distanceMatrix);
  std::cout << nClients << " " << nVehicles << "\n";
}

