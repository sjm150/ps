#include <iostream>

int main() {
  int N;
  scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    int j = 0;
    for(; j < N - i; j++) printf(" ");
    for(; j < N; j++) printf("*");
    printf("\n");
  }

  return EXIT_SUCCESS;
}
