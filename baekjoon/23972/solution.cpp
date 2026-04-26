#include <iostream>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int K, N;
  std::cin >> K >> N;
  if(N == 1) std::cout << -1 << '\n';
  else std::cout << K+1 + ((K-1)/(N-1)) << '\n';

  return 0;
}
