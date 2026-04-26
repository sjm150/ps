#include <iostream>

int main() {
  int T;
  int A, B;
  std::cin.tie(NULL);
  std::cin.sync_with_stdio(false);

  std::cin >> T;
  for(int i = 0; i < T; i++) {
    std::cin >> A >> B;
    std::cout << A+B << "\n";
  }

  return EXIT_SUCCESS;
}
