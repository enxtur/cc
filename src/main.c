#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib.h"

int main(int argc, char *argv[]) {
  int mode = 0;
  char *file;

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0) {
      mode = 1;
    } else if (strcmp(argv[i], "-l") == 0) {
      mode = 2;
    } else if (strcmp(argv[i], "-w") == 0) {
      mode = 3;
    } else if (strcmp(argv[i], "-m") == 0) {
      mode = 4;
    } else {
      file = argv[i];
    }
  }

  if (file == NULL) {
    printf("provide file!\n");
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
      struct Count count = countAll(file);
      printf("%d %d %d %s\n", count.bytes, count.lines, count.words, file);
      break;
  }

  return 0;
}