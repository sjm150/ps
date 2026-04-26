#include <iostream>

int main() {
  std::string S;
  std::cin >> S;

  int pos[26];
  for(int i = 0; i < 26; i++) {
    pos[i] = -1;
  }

  for(int i = 0; i < S.length(); i++) {
    if(pos[S.at(i) - 'a'] == -1) pos[S.at(i) - 'a'] = i;
  }

  for(int i = 0; i < 25; i++) {
    printf("%d ", pos[i]);
  }
  printf("%d\n", pos[25]);

  return EXIT_SUCCESS;
}
