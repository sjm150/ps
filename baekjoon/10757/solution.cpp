#include <iostream>

int main() {
  char *A, *B;
  scanf("%ms %ms", &A, &B);

  int len_A = 0, len_B = 0, len;
  char *ptr;
  ptr = A;
  while(*ptr != '\0') {
    len_A++;
    ptr++;
  }
  ptr = B;
  while(*ptr != '\0') {
    len_B++;
    ptr++;
  }

  len = std::max(len_A, len_B);
  char *ans = new char[len];
  ans[len-1] = A[len_A-1] + B[len_B-1] - '0';
  for(int i = 2; i <= len; i++) {
    if(ans[len-i+1] > '9') {
      ans[len-i+1] -= 10;
      ans[len-i] = '1';
    } else {
      ans[len-i] = '0';
    }
    if(len_A - i >= 0) ans[len-i] += A[len_A - i] - '0';
    if(len_B - i >= 0) ans[len-i] += B[len_B - i] - '0';
  }

  printf("%d%s\n", ans[0] - '0', ans+1);

  return EXIT_SUCCESS;
}
