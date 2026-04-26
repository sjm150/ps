#include <iostream>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int H, W, N, M;
  std::cin >> H >> W >> N >> M;
  std::cout << ((H+N)/(N+1))*((W+M)/(M+1)) << '\n';

  return 0;
}
