#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include "lib.h"

#define MODE_HELP 1
#define MODE_BYTES 2
#define MODE_LINES 3
#define MODE_WORDS 4
#define MODE_W_BYTES 5 // wide bytes

int main(int argc, char *argv[]) {
  int mode = 0;
  char *file = NULL;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0) {
      mode = MODE_BYTES;
    } else if (strcmp(argv[i], "-l") == 0) {
      mode = MODE_LINES;
    } else if (strcmp(argv[i], "-w") == 0) {
      mode = MODE_WORDS;
    } else if (strcmp(argv[i], "-m") == 0) {
      mode = MODE_W_BYTES;
    } else {
      if (argv[i][0] != '-') {
        file = argv[i];
      }
    }
  }

  FILE *fptr = file == NULL ? stdin : fopen(file, "r");
  
  if (fptr == NULL) {
    printf("error: unable to open file or pipe\n");
    exit(1);
  }
  
  struct Count c = {0, 0, 0, 0};
  char ch;

  while((ch = fgetc(fptr)) != EOF) {
    count(ch, &c);
  }
  
  if (c.in_word) {
    c.words++;
  }

  if (file != NULL) {
    fclose(fptr);
  }

  switch (mode) {
    case MODE_BYTES:
      printf(file == NULL ? "\t%d\n" : "\t%d\t%s\n", c.bytes, file);
      break;
    case MODE_LINES:
      printf(file == NULL ? "\t%d\n" : "\t%d\t%s\n", c.lines, file);
      break;
    case MODE_WORDS:
      printf(file == NULL ? "\t%d\n" : "\t%d\t%s\n", c.words, file);
      break;
    case MODE_W_BYTES:
      if (file == NULL) {
        printf("\t%d\n", c.bytes); // For stdin, -m is same as -c
      } else {
        printf("\t%d\t%s\n", countMultibyteCharacters(file), file);
      }
      break;
    default:
      printf(file == NULL ? "\t%d\t%d\t%d\n" : "\t%d\t%d\t%d\t%s\n", c.lines, c.words, c.bytes, file);
      break;
  }

  return 0;
}