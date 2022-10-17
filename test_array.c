#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"

int main(void)
{
  intarray  toto;
  int i;

  i = 0;
  toto = intarray_create(10);
  while (i < toto.len)
  {
    toto.data[i] = i * 2 + 8;
    i++;
  }
  intarray_set(toto, 3, -12);
  intarray_set(toto, 8, 1);
  intarray_sort1(toto);
  intarray_debug(toto);
  intarray_destroy(toto);
  return (0);
}