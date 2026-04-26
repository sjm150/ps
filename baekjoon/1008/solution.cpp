#include <iostream>
#include <iomanip>

int main() {
  double A, B;
  std::cin >> A >> B;

  std::cout << std::setprecision(11) << A/B << std::endl;

  return EXIT_SUCCESS;
}
