#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int sum = 0;
  char c;
  for(int i = 0; i < N; i++) {
    std::cin >> c;
    sum += c - '0';
  }

  std::cout << sum << std::endl;

  return EXIT_SUCCESS;
}
