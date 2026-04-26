#include <iostream>

bool check666(int num) {
  int count = 0;
  while(num) {
    if(num%10 == 6) count++;
    else count = 0;

    if(count == 3) return true;
    num /= 10;
  }

  return false;
}

int main() {
  int N;
  scanf("%d", &N);

  int num = 666;
  for(int i = 0; i < N; num++) {
    if(check666(num)) i++;
  }

  printf("%d\n", num-1);

  return 0;
}
