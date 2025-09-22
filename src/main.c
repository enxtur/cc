#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include "lib.h"

int main(int argc, char *argv[]) {
  int mode = 0;
  char *file = NULL;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0) {
      mode = 1;
    } else if (strcmp(argv[i], "-l") == 0) {
      mode = 2;
    } else if (strcmp(argv[i], "-w") == 0) {
      mode = 3;
    } else if (strcmp(argv[i], "-m") == 0) {
      mode = 4;
    } else {
      if (argv[i][0] != '-') {
        file = argv[i];
      }
    }
  }

  struct Count c = {0, 0, 0, 0};
  char ch;
  FILE *fptr = file == NULL ? stdin : fopen(file, "r");

  if (fptr == NULL) {
    printf("error: unable to open file or pipe\n");
    exit(1);
  }

  while((ch = fgetc(fptr)) != EOF) {
    count(ch, &c);
  }
  
  if (file != NULL) {
    fclose(fptr);
  }

  if (c.in_word) {
    c.words++;
  }
  

  switch (mode) {
    case 1:
      if (file == NULL) {
        printf("%d\n", c.bytes);
      } else {
        printf("%d %s\n", c.bytes, file);
      }
      break;
    case 2:
      if (file == NULL) {
        printf("%d\n", c.lines);
      } else {
        printf("%d %s\n", c.lines, file);
      }
      break;
    case 3:
      if (file == NULL) {
        printf("%d\n", c.words);
      } else {
        printf("%d %s\n", c.words, file);
      }
      break;
    case 4:
      if (file == NULL) {
        printf("%d\n", c.bytes); // For stdin, -m is same as -c
      } else {
        printf("%d %s\n", countMultibyteCharacters(file), file);
      }
      break;
    default:
      if (file == NULL) {
        printf("%d %d %d\n", c.bytes, c.lines, c.words);
      } else {
        printf("%d %d %d %s\n", c.bytes, c.lines, c.words, file);
      }
      break;
  }

  return 0;
}