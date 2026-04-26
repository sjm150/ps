#include <iostream>

char board[50][50];

int num_to_color(int x, int y, char std) {
  int num = 0;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if((i+j)%2 == 0) {
        if(board[x+i][y+j] != std) num++;
      } else {
        if(board[x+i][y+j] == std) num++;
      }
    }
  }
  return num;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; i++) {
    std::cin >> board[i];
  }

  int min = 2500, temp;
  for(int i = 0; i < N-7; i++) {
    for(int j = 0; j < M-7; j++) {
      temp = std::min(num_to_color(i, j, 'W'), num_to_color(i , j, 'B'));
      if(min > temp) min = temp;
    }
  }

  printf("%d\n", min);

  return 0;
}
