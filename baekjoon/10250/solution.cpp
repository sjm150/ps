#include <iostream>

int main() {
  int T;
  std::cin >> T;

  for(int cases = 0; cases < T; cases++) {
    int H, W, N;
    std::cin >> H >> W >> N;
    printf("%d%.2d\n", (N%H == 0) ? H : N%H, (N-1)/H + 1);
  }

  return EXIT_SUCCESS;
}
