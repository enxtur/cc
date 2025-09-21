#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib.h"

int main(int argc, char *argv[]) {
  int mode = 0;
  char *file;

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0) {
      if (argc <= (i + 1)) {
        printf("provide file!\n");
        exit(1);
      }
      mode = 1;
      file = argv[i + 1];
    } else if (strcmp(argv[i], "-l") == 0) {
      if (argc <= (i + 1)) {
        printf("provide file!\n");
        exit(1);
      }
      mode = 2;
      file = argv[i + 1];
    } else if (strcmp(argv[i], "-w") == 0) {
      if (argc <= (i + 1)) {
        printf("provide file!\n");
        exit(1);
      }
      mode = 3;
      file = argv[i + 1];
    } else if (strcmp(argv[i], "-m") == 0) {
      if (argc <= (i + 1)) {
        printf("provide file!\n");
        exit(1);
      }
      mode = 4;
      file = argv[i + 1];
    }
  }

  switch (mode) {
    case 1:
      printf("%d %s\n", countBytes(file), file);
      break;
    case 2:
      printf("%d %s\n", countLines(file), file);
      break;
    case 3:
      printf("%d %s\n", countWords(file), file);
      break;
    case 4:
      printf("%d %s\n", countMultibyteCharacters(file), file);
      break;
    default:
      printf("unrecognized mode");
      break;
  }

  return 0;
}