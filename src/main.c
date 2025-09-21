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

  FILE *fptr = fopen(file, "r");

  if (fptr == NULL) {
    printf("error: unable to open file!\n");
    exit(1);
  }

  struct Count c = {0, 0, 0, 0};
  char ch;

  while((ch = fgetc(fptr)) != EOF) {
    count(ch, &c);
  }

  switch (mode) {
    case 1:
      printf("%d %s\n", c.bytes, file);
      break;
    case 2:
      printf("%d %s\n", c.lines, file);
      break;
    case 3:
      printf("%d %s\n", c.words, file);
      break;
    case 4:
      printf("%d %s\n", countMultibyteCharacters(file), file);
      break;
    default:
      printf("%d %d %d %s\n", c.bytes, c.lines, c.words, file);
      break;
  }

  fclose(fptr);

  return 0;
}