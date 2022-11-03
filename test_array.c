#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"
#include "tools.h"

int main(int argc, char **argv)
{
  int i;

  i = 0;
  while (i < argc)
  {
    printf("%d\n", string_to_int(argv[i]));
    i++;
  }
  return (0);
}