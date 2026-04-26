#include <iostream>

int main() {
  int T;
  std::string S;
  int R;

  std::cin >> T;
  for(int i = 0; i < T; i++) {
    std::cin >> R >> S;

    for(int j = 0; j < S.length(); j++) {
      for(int k = 0; k < R; k++) {
        printf("%c", S.at(j));
      }
    }
    printf("\n");
  }


  return EXIT_SUCCESS;
}
