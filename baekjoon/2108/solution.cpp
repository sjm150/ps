#include <iostream>

int main() {
  int N;
  scanf("%d", &N);
  int *num = new int[N];
  for(int i = 0; i < N; i++) {
    scanf("%d", &num[i]);
  }

  int count[8001] = {0,};
  int sum = 0;
  int min = 4000, max = -4000;
  int mode = -4000, dup = 2;
  for(int i = 0; i < N; i++) {
    count[4000+num[i]]++;
    sum += num[i];
    if(num[i] < min) min = num[i];
    if(num[i] > max) max = num[i];
  }
  int idx = 0;
  for(int i = min; i <= max; i++) {
    if(count[mode+4000] == count[i+4000] && dup > 0) {
      mode = i;
      dup--;
    } else if(count[mode+4000] < count[i+4000]) {
      mode = i;
      dup = 1;
    }
    for(int j = idx; idx < j + count[i+4000]; idx++) num[idx] = i;
  }

  int mean = sum/N;
  mean += (2*(sum-mean*N)) / N;
  printf("%d\n%d\n%d\n%d\n", mean, num[N/2], mode, max-min);

  return 0;
}
