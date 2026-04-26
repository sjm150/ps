#include <iostream>

int main() {
  int A, B, C;
  std::cin >> A >> B >> C;

  int ans;
  if(B < C) ans = A/(C-B) + 1;
  else ans = -1;
  std::cout << ans << std::endl;

  return EXIT_SUCCESS;
}
