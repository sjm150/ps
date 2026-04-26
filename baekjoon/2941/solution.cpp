#include <string.h>
#include <iostream>

int main() {
  char* word;
  scanf("%ms", &word);

  char* ptr = word;
  int i = 0, num = 0;
  while(*ptr != '\0') {
    switch(*ptr) {
      case 'c':
        if((strncmp(ptr, "c=", 2) == 0) || (strncmp(ptr, "c-", 2) == 0)) ptr += 2;
        else ptr++;
        break;
      case 'd':
        if(strncmp(ptr, "dz=", 3) == 0) ptr += 3;
        else if(strncmp(ptr, "d-", 2) == 0) ptr += 2;
        else ptr++;
        break;
      case 'l':
        if(strncmp(ptr, "lj", 2) == 0) ptr += 2;
        else ptr++;
        break;
      case 'n':
        if(strncmp(ptr, "nj", 2) == 0) ptr += 2;
        else ptr++;
        break;
      case 's':
        if(strncmp(ptr, "s=", 2) == 0) ptr += 2;
        else ptr++;
        break;
      case 'z':
        if(strncmp(ptr, "z=", 2) == 0) ptr += 2;
        else ptr++;
        break;
      default:
        ptr++; break;
    }
    num++;
  }
  free(word);

  printf("%d\n", num);

  return EXIT_SUCCESS;
}
