#include <iostream>

int main() {
  int cases;
  std::cin >> cases;

  int score, sum;
  std::string res;
  for(int i = 0; i < cases; i++) {
    score = 0, sum = 0;
    std::cin >> res;
    for(int j = 0; j < res.length(); j++) {
      if(res.at(j) == 'O') {
        sum += ++score;
      } else if(res.at(j) == 'X') {
        score = 0;
      }
    }
    std::cout << sum << std::endl;
  }

  return EXIT_SUCCESS;
}
