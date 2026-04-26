#include <iostream>
#include <string>

int main() {
  int A;
  std::string B;
  std::cin >> A >> B;

  std::cout << A * (B.at(2) - '0') << std::endl
            << A * (B.at(1) - '0') << std::endl
            << A * (B.at(0) - '0') << std::endl
            << A * stoi(B) << std::endl;

  return EXIT_SUCCESS;
}
