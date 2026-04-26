#include <iostream>
#include <cmath>

int main() {
  int M, N;
  std::cin >> M >> N;

  int sum = 0, min = -1;
  for(int i = M; i <= N; i++) {
    if(i < 2) continue;

    int j;
    for(j = sqrt(i); j >= 2; j--) {
      if(i%j == 0) {
        break;
      }
    }

    if(j == 1) {
      sum += i;
      if(min == -1) min = i;
    }
  }

  if(min != -1) std::cout << sum << std::endl;
  std::cout << min << std::endl;

  return EXIT_SUCCESS;
}
