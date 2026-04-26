#include <iostream>

int main() {
  int N;
  scanf("%d", &N);

  int *w = new int[N];
  int *h = new int[N];
  int *k = new int[N];
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &w[i], &h[i]);
    k[i] = 1;
  }

  for(int i = 0; i < N-1; i++) {
    for(int j = i+1; j < N; j++) {
      if(w[i] > w[j] && h[i] > h[j]) k[j]++;
      else if(w[i] < w[j] && h[i] < h[j]) k[i]++;
    }
  }

  for(int i = 0; i < N-1; i++) printf("%d ", k[i]);
  printf("%d\n", k[N-1]);

  return 0;
}
