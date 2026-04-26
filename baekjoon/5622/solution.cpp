#include <iostream>

int main() {
  std::string dial;
  std::cin >> dial;

  int time = 0;
  int num;
  for(int i = 0; i < dial.length(); i++) {
    switch(dial.at(i)) {
      case 'A': case 'B': case 'C': num = 2; break;
      case 'D': case 'E': case 'F': num = 3; break;
      case 'G': case 'H': case 'I': num = 4; break;
      case 'J': case 'K': case 'L': num = 5; break;
      case 'M': case 'N': case 'O': num = 6; break;
      case 'P': case 'Q': case 'R': case 'S': num = 7; break;
      case 'T': case 'U': case 'V': num = 8; break;
      case 'W': case 'X': case 'Y': case 'Z': num = 9; break;
    }
    time += 1 + num;
  }

  std::cout << time << std::endl;

  return EXIT_SUCCESS;
}
