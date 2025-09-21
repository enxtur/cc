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

int countBytes(char *file) {
  FILE *fptr = fopen(file, "r");
  char buffer[BUFFER_SIZE];

  if (fptr == NULL) {
    printf("error: unable to open file!\n");
    exit(1);
  }

  int count = 0;

  while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
    count += strlen(buffer);
  }

  fclose(fptr);

  return count;
}

int countLines(char *file) {
  FILE *fptr = fopen(file, "r");
  char ch;

  if (fptr == NULL) {
    printf("error: unable to open file!\n");
    exit(1);
  }

  int count = 0;

  while((ch = fgetc(fptr)) != EOF) {
    if (ch == END_OF_LINE) {
      count++;
    }
  }

  fclose(fptr);

  return count;
}

int countWords(char *file) {
  FILE *fptr = fopen(file, "r");
  char ch;

  if (fptr == NULL) {
    printf("error: unable to open file!\n");
    exit(1);
  }

  int count = 0;
  int inWord = 0;

  while((ch = fgetc(fptr)) != EOF) {
    if (ch == SPACE || ch == END_OF_LINE || ch == TAB) {
      if (inWord) {
        count++;
        inWord = 0;
      }
    } else {
      inWord = 1;
    }
  }

  if (inWord) {
    count++;
  }

  fclose(fptr);

  return count;
}

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

struct Count countAll(char *file) {
  FILE *fptr = fopen(file, "r");
  char ch;

  if (fptr == NULL) {
    printf("error: unable to open file!\n");
    exit(1);
  }

  struct Count count = {0, 0, 0};

  int inWord = 0;

  while((ch = fgetc(fptr)) != EOF) {
    count.bytes++;
    if (ch == SPACE || ch == END_OF_LINE || ch == TAB) {
      if (inWord) {
        count.words++;
        inWord = 0;
      }

      if (ch == END_OF_LINE) {
        count.lines++;
      }
    } else {
      inWord = 1;
    }
  }

  if (inWord) {
    count.words++;
  }

  fclose(fptr);

  return count;
}