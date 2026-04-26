#include <iostream>

int main() {
  int x, y, w, h;
  scanf("%d %d %d %d", &x, &y, &w, &h);

  printf("%d\n", std::min(std::min(x, w-x), std::min(y, h-y)));

  return EXIT_SUCCESS;
}
