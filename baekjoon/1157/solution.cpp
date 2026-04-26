#include <iostream>

int main() {
  std::string word;
  char temp, most;
  int appearance = 0;
  int used[26];

  for(int i = 0; i < 26; i++) {
    used[i] = 0;
  }

  std::cin >> word;
  for(int i = 0; i < word.length(); i++) {
    temp = word.at(i);
    if(temp >= 'a') {
      temp += 'A' - 'a';
    }

    used[temp - 'A']++;
  }

  for(int i = 0; i < 26; i++) {
    if(used[i] > appearance) {
      most = i + 'A';
      appearance = used[i];
    } else if(used[i] == appearance) {
      most = '?';
    }
  }

  std::cout << most << std::endl;

  return EXIT_SUCCESS;
}
