#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"

intarray  intarray_create(int len)
{
  intarray  tab;
  int i;

  i = 0;
  tab.len = len;
  tab.data = malloc (len * sizeof(int));
  while(i < len)
  {
    tab.data[i] = 0;
    i++;
  }
  return (tab);
}

intarray  intarray_concat(intarray tab1, intarray tab2)
{
  intarray tab;
  int len;
  int i;
  int j;

  i = 0;
  j = 0;
  len = tab1.len + tab2.len;
  tab = intarray_create(len);
  while (i < tab1.len)
  {
    tab.data[j] = tab1.data[i];
    i++;
    j++;
  }
  i = 0;
  while (i < tab2.len)
  {
    tab.data[j] = tab2.data[i];
    i++;
    j++;
  }
  return (tab);
}

void      intarray_swap(int *first, int *second)
{
  int tmp;
  
  tmp = *first;
  *first = *second;
  *second = tmp;
}

void      intarray_sort1(intarray tab)
{
  int i;
  int index_min;

  i = 0;
  while (i <= tab.len - 2)
  {
    index_min = intarray_get_index_of_min_from(tab, i);
    intarray_swap(tab.data + i, tab.data + index_min);
    i++;
  }
}

void      intarray_set(intarray tab, int index, int value)
{
  if ((index < 0) || (index >= tab.len))
  {
    printf("intarray_set :\nL'index %d est invalide.\n", index);
    printf("Les valeurs valides sont entre 0 et %d.\n", tab.len - 1);
    return ;
  }
  tab.data[index] = value;
}

void      intarray_print_positive_values(intarray tab)
{
  int i;

  i = 0;
  while(i < tab.len)
  {
    if (tab.data[i] >= 0)
      printf("%d ", tab.data[i]);
    i++;
  }
}

void      intarray_debug(intarray tab)
{
  int i;

  i = 0;
  printf("[ ");
  while (i < tab.len - 1)
  {
    printf("%d, ", tab.data[i]);
    i++;
  }
  printf("%d", tab.data[tab.len - 1]);
  printf(" ]");
}

void      intarray_destroy(intarray tab)
{
  free(tab.data);
}

int       intarray_length(intarray tab)
{
  return tab.len;
}

int       intarray_get(intarray tab, int index)
{
  if ((index < 0) || (index >= tab.len))
  {
    printf("intarray_get :\nL'index %d est invalide.\n", index);
    printf("Les valeurs valides sont entre 0 et %d.\n", tab.len - 1);
    return (-1);
  }
  return tab.data[index];
}

int       intarray_search(intarray tab, int n)
{
  int i;

  i = 0;
  while(i < tab.len)
  {
    if (tab.data[i] == n)
      return (1);
    i++;
  }
  return (0);
}

int       intarray_nb_occurences(intarray tab, int n)
{
  int i;
  int nb;

  nb = 0;
  i = 0;
  while(i < tab.len)
  {
    if (tab.data[i] == n)
      nb++;
    i++;
  }
  return (nb);
}

int       intarray_get_min(intarray tab)
{
  int index_min = intarray_get_index_of_min(tab);
  return (tab.data[index_min]);
}

int       intarray_get_index_of_min(intarray tab)
{
  return (intarray_get_index_of_min_from(tab, 0));
}

int       intarray_get_index_of_min_from(intarray tab, int n)
{
  int i;
  int index;
  int min;

  if ((n < 0) || (n >= tab.len))
  {
    printf("intarray_get_index_of_min_from : l'index est invalide.\n");
    printf("Les valeurs valides sont comprise entre 0 et %d.\n", tab.len - 1);
    return (0);
  }

  i = n + 1;
  index = n;
  min = tab.data[n];
  while (i < tab.len)
  {
    if (min > tab.data[i])
    {
      min = tab.data[i];
      index = i;
    }
    i++;
  }
  return (index);
}
