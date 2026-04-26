#include <iostream>

int main() {
  int H, M;
  std::cin >> H >> M;

  if(M < 45) {
    H--;
    if(H<0) H += 24;
    M += 15;
  } else {
    M -= 45;
  }

  std::cout << H << " " << M << std::endl;

  return EXIT_SUCCESS;
}
