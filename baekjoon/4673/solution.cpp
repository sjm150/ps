#include <iostream>
#include <set>

int main() {
  std::set<int> selfnums;
  for(int i = 1; i <= 10000; i++) {
    selfnums.insert(i);
  }

  int d_n;
  std::string nstr;
  for(int n = 1; n < 10000; n++) {
    nstr = std::to_string(n);
    d_n = n;
    for(int i = 0; i < nstr.length(); i++) {
      d_n += nstr.at(i) - '0';
    }
    //printf("%d\n", d_n);

    selfnums.erase(d_n);
  }

  for(int element : selfnums) {
    printf("%d\n", element);
  }

  return EXIT_SUCCESS;
}
