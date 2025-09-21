#ifndef LIB_H
#define LIB_H

int countBytes(char *file);
int countLines(char *file);
int countWords(char *file);
int countMultibyteCharacters(char *file);
struct Count {
  int bytes;
  int lines;
  int words;
};
struct Count countAll(char *file);

#endif