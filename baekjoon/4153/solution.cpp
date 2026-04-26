#include <iostream>

void swap(int *a, int *b) {
  int temp;
  temp = *b;
  *b = *a;
  *a = temp;
}

int main() {
  while(1) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == 0 & b == 0 & c == 0) break;

    if(a>c) swap(&a, &c);
    if(b>c) swap(&b, &c);

    printf("%s\n", (a*a + b*b == c*c) ? "right" : "wrong");
  }

  return EXIT_SUCCESS;
}
