#include <iostream>

int main() {
  char* sentence;
  int words = 0;
  while(scanf("%ms", &sentence) != EOF) {
    words++;
  }

  printf("%d\n", words);

  return EXIT_SUCCESS;
}
