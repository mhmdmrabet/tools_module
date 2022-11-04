#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "tools.h"

int main(int argc, char **argv)
{
  intarray tab;
  int i;
  int n;
  int ok;
  int min;
  int max;

  tab = empty_intarray_create(argc - 1);
  min = 0;
  max = 0;
  i = 1;
  n = 0;
  ok = 0;
  while (i < argc)
  {
    n = safe_string_to_int(argv[i], &ok);
    if (ok)
    {
      intarray_add(tab, n);
    }
    i++;
  }
  if (tab->len == 0)
  {
    printf("Aucun nombre. Stat impossible !\n");
    intarray_destroy(tab);
    return (0);
  }
  max = intarray_get_max(tab);
  min = intarray_get_min(tab);
  intarray_debug(tab);
  printf("Somme = %d\n", intarray_sum(tab));
  printf("Minimum = %d\n", min);
  printf("Maximum = %d\n", max);
  printf("Étendu = %d\n", max - min);
  printf("Moyenne = %f\n", intarray_average(tab));
  printf("Mediane = %f\n", intarray_median(tab));
  intarray_destroy(tab);
  return (0);
}