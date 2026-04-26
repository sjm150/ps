#include <iostream>

int main() {
  int T;
  std::cin >> T;

  for(int cases = 0; cases < T; cases++) {
    int k, n;
    scanf("%d\n%d", &k, &n);
    int num[k+1][n];
    for(int i = 0; i <= k; i++) num[i][0] = 1;
    for(int j = 0; j < n; j++) num[0][j] = j+1;
    for(int i = 1; i <= k; i++) {
      for(int j = 1; j < n; j++) {
        num[i][j] = 0;
      }
    }

    for(int i = 1; i <= k; i++) {
      for(int j = 1; j < n; j++) {
        num[i][j] = num[i-1][j] + num[i][j-1];
      }
    }

    printf("%d\n", num[k][n-1]);
  }

  return EXIT_SUCCESS;
}
