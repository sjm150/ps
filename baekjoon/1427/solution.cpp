#include <iostream>

int compare(const void *a, const void *b) {
  if(*(char*)a == *(char*)b) return 0;
  else return (*(char*)a<*(char*)b) ? 1 : -1;
}

int main() {
  char *N;
  scanf("%ms", &N);
  std::qsort(N, (size_t) std::to_string(atoi(N)).length(), sizeof(char), compare);
  std::cout << N << std::endl;
  return 0;
}
