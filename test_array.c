#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"

int main(int argc, char **argv)
{
  int i;

  i = 0;
  while (i < argc)
  {
    printf("%s\n", argv[i]);
    i++;
  }
  return (0);
}