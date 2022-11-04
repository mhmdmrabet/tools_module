#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"
#include "tools.h"

int main(void)
{
  intarray tab;
  intarray tab2;

  tab = intarray_create(10);
  tab2 = empty_intarray_create(0);
  intarray_set(tab, 4, 10);
  intarray_set(tab, 9, 25);
  intarray_delete(tab, 0);
  intarray_delete(tab, 1);
  intarray_add(tab, 22);
  intarray_add(tab, 24);
  intarray_debug(tab);
  intarray_debug(tab2);
  intarray_destroy(tab);
  intarray_destroy(tab2);
  return (0);
}