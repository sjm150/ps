#include <iostream>

int main() {
  int N;
  std::cin >> N;

  if(N < 100) {
    std::cout << N << std::endl;
    return EXIT_SUCCESS;
  }

  int num = 99;
  std::string nstr;
  for(int n = 111; n <= N; n++) {
    nstr = std::to_string(n);
    if(nstr.at(1) * 2 == nstr.at(0) + nstr.at(2)) num++;
  }

  std::cout << num << std::endl;

  return EXIT_SUCCESS;
}
