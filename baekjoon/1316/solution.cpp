#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int num = N;
  for(int i = 0; i < N; i++) {
    std::string word;
    std::cin >> word;
    bool used[26] = {false,};

    int idx = 0;
    while(idx < word.length()) {
      char c = word.at(idx);
      if(used[c - 'a'] == false) {
        used[c - 'a'] = true;
        while(idx < word.length() && (word.at(idx) == c)) idx++;
      } else {
        num--;
        break;
      }
    }
  }

  std::cout << num << std::endl;

  return EXIT_SUCCESS;
}
