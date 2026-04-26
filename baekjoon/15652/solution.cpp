#include <iostream>
using namespace std;

int N, M;
int seq[8];

void print_comb(int last, int depth) {
  if(depth == M) {
    for(int i = 0; i < M-1; i++) cout << seq[i] << ' ';
    cout << seq[M-1] << '\n';
    return;
  } else {
    for(int i = last; i <= N; i++) {
      seq[depth] = i;
      print_comb(i, depth+1);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    seq[0] = i;
    print_comb(i, 1);
  }

  return 0;
}
