#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int num = N / 5;
  switch(N % 5) {
    case 1: num = (N>5) ? num+1 : -1; break;
    case 2: num = (N>10) ? num+2 : -1; break;
    case 3: num++; break;
    case 4: num = (N>5) ? num+2 : -1; break;
  }

  std::cout << num << std::endl;

  return EXIT_SUCCESS;
}
