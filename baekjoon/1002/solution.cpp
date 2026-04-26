#include <iostream>

#define pow2(x) ((x)*(x))

int main() {
  int T;
  scanf("%d", &T);

  for(int cases = 0; cases < T; cases++) {
    int x1, y1, r1, x2, y2, r2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    int dist = pow2(x1-x2) + pow2(y1-y2);
    if(dist == 0) {
      printf("%d\n", (r1 == r2) ? -1 : 0);
    } else if(dist > pow2(std::max(r1, r2))) {
      printf("%d\n", (dist > pow2(r1+r2)) ? 0 : (dist == pow2(r1+r2)) ? 1: 2);
    } else {
      printf("%d\n", (dist < pow2(r1-r2)) ? 0 : (dist == pow2(r1-r2)) ? 1: 2);
    }
  }

  return EXIT_SUCCESS;
}
