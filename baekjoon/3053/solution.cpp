#include <iostream>

#define pi 3.14159265359

int main() {
  int R;
  scanf("%d", &R);

  printf("%.6f\n%.6f\n", pi*R*R, (double) 2*R*R);

  return EXIT_SUCCESS;
}
