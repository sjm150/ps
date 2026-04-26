#include <iostream>

#define N 9999

int main() {
  int T;
  scanf("%d", &T);

  bool prime[N];
  prime[0] = prime[1] = false;
  for(int i = 2; i < N; i++) prime[i] = true;

  for(int i = 2; i < N; i++) {
    if(!prime[i]) continue;
    for(int j = 2*i; j < N; j += i) prime[j] = false;
  }

  for(int cases = 0; cases < T; cases++) {
    int n;
    scanf("%d", &n);

    for(int diff = 0; n/2 - diff > 1; diff++) {
      if((prime[n/2 - diff] & prime[n/2 + diff]) == true) {
        printf("%d %d\n", n/2- diff, n/2 + diff);
        break;
      }
    }
  }

  return EXIT_SUCCESS;
}
