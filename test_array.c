#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"
#include "tools.h"
#include "mstr.h"

int main(int argc, char **argv)
{
  mstr	tab;
  mstr	tmp;
  int	i;

  tab = standard_empty_mstr_create();
  for (i = 1; i < argc; i++)
  {
	tmp = regstr_to_mstr(argv[i]);
	D_mstr_concat(tab, tmp);
	mstr_destroy(tmp);
  }

  mstr_debug(tab);
  mstr_destroy(tab);
  return (0);
}