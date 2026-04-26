#include <iostream>

int main() {
  int A, B;
  std::cin >> A >> B;

  std::string strA = std::to_string(A),
              strB = std::to_string(B);

  int revA, revB;
  revA = 100*strA.at(2) + 10*strA.at(1) + strA.at(0) - 111*'0';
  revB = 100*strB.at(2) + 10*strB.at(1) + strB.at(0) - 111*'0';

  std::cout << std::max(revA, revB) << std::endl;

  return EXIT_SUCCESS;
}
