#include <iostream>

int main() {
  int N, X, num;
  bool isfirst = true;
  scanf("%d %d", &N, &X);

  for(int i = 0; i < N; i++) {
    scanf("%d", &num);
    if(num < X) {
      if(isfirst) isfirst = false;
      else printf(" ");
      printf("%d", num);
    }
  }
  printf("\n");

  return EXIT_SUCCESS;
}
