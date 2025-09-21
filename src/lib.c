#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countBytes(char *file) {
  FILE *fptr = fopen(file, "r");
  char buffer[1024];

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
  char end_of_line = '\n';

  if (fptr == NULL) {
    printf("error: unable to open file!\n");
    exit(1);
  }

  int count = 0;

  while((ch = fgetc(fptr)) != EOF) {
    if (ch == end_of_line) {
      count++;
    }
  }

  fclose(fptr);

  return count;
}