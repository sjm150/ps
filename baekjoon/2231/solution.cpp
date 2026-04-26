#include <iostream>

int main() {
  int N;
  scanf("%d", &N);

  int len = 1;
  for(int i = 10; i <= 1000000; i *= 10) {
    if(N/i > 0) len++;
    else break;
  }

  int ans, sum, digit;
  for(int i = std::max(N - 9*len, 1); i < N; i++) {
    ans = i;
    sum = ans;
    while(ans) {
      digit = ans % 10;
      ans /= 10;
      sum += digit;
    }
    if(sum == N) {
      printf("%d\n", i);
      return 0;
    }
  }

  printf("0\n");
  return 0;
}
