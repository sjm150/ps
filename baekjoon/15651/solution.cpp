#include <iostream>

int N, M;
int seq[8];

void print_seq(int size) {
  if(size == M) {
    for(int i = 0 ; i < M-1; i++) std::cout << seq[i] << ' ';
    std::cout << seq[M-1] << '\n';
    return;
  } else {
    for(int i = 1; i <= N; i++) {
      seq[size] = i;
      print_seq(size+1);
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    seq[0] = i;
    print_seq(1);
  }

  return 0;
}
