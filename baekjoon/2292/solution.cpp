#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int num = 1, access_able = 1;
  while(access_able < N) {
    access_able += num * 6;
    num++;
  }

  std::cout << num << std::endl;

  return EXIT_SUCCESS;
}
