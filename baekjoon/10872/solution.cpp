#include <iostream>

int fact(int n) {
  if(n == 0) return 1;
  else return n * fact(n-1);
}

int main() {
  int N;
  scanf("%d", &N);

  printf("%d\n", fact(N));
}
