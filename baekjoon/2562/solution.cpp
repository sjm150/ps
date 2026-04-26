#include <iostream>

int main() {
  int temp, pos;
  int max = 1;

  for(int i = 0; i < 9; i++) {
    scanf("%d", &temp);
    if(max < temp) {
      max = temp;
      pos = i + 1;
    }
  }

  printf("%d\n%d\n", max, pos);

  return EXIT_SUCCESS;
}
