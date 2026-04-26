#include <iostream>

int main() {
  int A, B;

  while(scanf("%d %d", &A, &B) != EOF) {
    printf("%d\n", A+B);
  }

  return EXIT_SUCCESS;
}
