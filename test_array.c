#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"
#include "tools.h"
#include "mstr.h"

int main(void)
{
  mstr tab;
  // int i;

  tab = regstr_to_mstr("Hello world !");
  // for (i = 1; i <= 100; i++)
  // {
  //   mstr_add(tab, i);
  // }

  mstr_debug(tab);
  mstr_destroy(tab);
  return (0);
}