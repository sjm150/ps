#include <iostream>
#include <iomanip>

int main() {
  int N, score;
  int sum = 0, max = 0;
  std::cin >> N;

  for(int i = 0; i < N; i++) {
    std::cin >> score;
    sum += score;
    if(score > max) max = score;
  }

  std::cout << std::setprecision(5) << (double) (sum*100)/(max*N) << std::endl;

  return EXIT_SUCCESS;
}
