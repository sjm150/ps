#include <iostream>

int main() {
  int N, temp, cycle = 0;

  scanf("%d", &N);
  temp = N;
  do {
    temp = (temp%10)*10 + ((temp%10 + temp/10) % 10);
    cycle++;
  } while(temp != N);

  printf("%d\n", cycle);

  return EXIT_SUCCESS;
}
