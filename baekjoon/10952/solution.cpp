#include <iostream>

int main() {
  int A, B;

  scanf("%d %d", &A, &B);
  while(A) {
    printf("%d\n", A+B);
    scanf("%d %d", &A, &B);
  }

  return EXIT_SUCCESS;
}
