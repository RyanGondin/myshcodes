#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 128

typedef struct Data {
  int dia, mes, ano;
} DATA;

typedef enum { false, true } bool;

int read_int(char *msg) {
  int n;
  printf(msg);
  scanf("%d", &n);
  return n;
}
float read_float(char *msg) {
  float n;
  printf(msg);
  scanf("%f", &n);
  return n;
}
char read_char(char *msg) {
  char c;
  printf(msg);
  scanf("%c", &c);
  return c;
}