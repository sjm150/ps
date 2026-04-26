#include <iostream>

int main() {
  int N, temp;
  int min = 1000000, max = -1000000;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &temp);
    if(temp < min) min = temp;
    if(max < temp) max = temp;
  }

  printf("%d %d\n", min, max);

  return EXIT_SUCCESS;
}
