#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
  int inWord = 0;  // Track if we're currently inside a word

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