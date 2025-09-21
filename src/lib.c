#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#include"lib.h"

#define BUFFER_SIZE 1024
#define END_OF_LINE '\n'
#define SPACE ' '
#define TAB '\t'

int countMultibyteCharacters(char *file) {
  if (setlocale(LC_CTYPE, "") == NULL) {
    printf("Error setting locale\n");
    exit(1);
  }

  FILE *fptr = fopen(file, "r");
  wint_t wc;
  int count = 0;

  if (fptr == NULL) {
    printf("error: unable to open file!\n");
    exit(1);
  }

  while ((wc = fgetwc(fptr)) != WEOF) {
    count++;
  }

  fclose(fptr);

  return count;
}

void count(char ch, struct Count *count) {
  count->bytes++;

  if (ch == END_OF_LINE) {
    count->lines++;
  }

  if (ch == SPACE || ch == END_OF_LINE || ch == TAB) {
    if (count->in_word) {
      count->words++;
      count->in_word = 0;
    }
  } else {
    count->in_word = 1;
  }
}