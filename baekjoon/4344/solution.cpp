#include <iostream>

int main() {
  int C;
  std::cin >> C;

  int N, *scores;
  int sum, over_mean;
  double mean;
  for(int i = 0; i < C; i++) {
    std::cin >> N;
    scores = new int[N];
    sum = 0, mean = 0, over_mean = 0;

    for(int j = 0; j < N; j++) {
      std::cin >> scores[j];
      sum += scores[j];
    }
    mean = (double) sum / N;
    for(int j = 0; j < N; j++) {
      if(scores[j] > mean) over_mean++;
    }

    std::cout.precision(3);
    std::cout.setf(std::ios::fixed);
    std::cout << (double) (over_mean*100)/N
              << "%" << std::endl;
  }


  return EXIT_SUCCESS;
}
