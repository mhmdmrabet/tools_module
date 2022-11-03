#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "tools.h"

int main(int argc, char **argv)
{
  intarray tab = intarray_create(argc - 1);
  int real_len_of_tab = 0;
  int i;
  int n;
  int ok;
  int min;
  int max;

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
      intarray_set(tab, real_len_of_tab, n);
      real_len_of_tab++;
    }
    i++;
  }
  tab.len = real_len_of_tab;
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