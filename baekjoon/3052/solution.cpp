#include <iostream>
#include <set>

int main() {
  int temp;
  std::set<int> remainders;

  for(int i = 0; i < 10; i++) {
    scanf("%d", &temp);
    remainders.insert(temp%42);
  }

  printf("%lu\n", remainders.size());

  return EXIT_SUCCESS;
}
