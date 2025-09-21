#ifndef LIB_H
#define LIB_H

struct Count {
  int bytes;
  int lines;
  int words;
  int in_word;
};
void count(char ch, struct Count *count);

int countMultibyteCharacters(char *file);

#endif