#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "tools.h"

void intarray_create_aux(intarray tab)
{
  int i;
  if (tab->alloc <= 0)
  {
    tab->alloc = 4;
    printf("intarray_create_aux : taille allouée <= 0.\nNous allouons %d à la place.\n", tab->alloc);
  }
  i = 0;
  tab->data = malloc(tab->alloc * sizeof(int));
  while (i < tab->alloc)
  {
    tab->data[i] = 0;
    i++;
  }
}

intarray intarray_create(int len)
{
  intarray tab;
  tab = malloc(sizeof(struct _intarray));
  tab->len = len;
  tab->alloc = len;
  intarray_create_aux(tab);
  return (tab);
}

intarray empty_intarray_create(int alloc)
{
  intarray tab;

  tab = malloc(sizeof(struct _intarray));
  tab->len = 0;
  tab->alloc = alloc;
  intarray_create_aux(tab);
  return (tab);
}

intarray intarray_concat(intarray tab1, intarray tab2)
{
  intarray tab;
  int len;
  int i;
  int j;

  i = 0;
  j = 0;
  len = tab1->len + tab2->len;
  tab = intarray_create(len);
  while (i < tab1->len)
  {
    tab->data[j] = tab1->data[i];
    i++;
    j++;
  }
  i = 0;
  while (i < tab2->len)
  {
    tab->data[j] = tab2->data[i];
    i++;
    j++;
  }
  return (tab);
}

intarray intarray_clone(intarray tab)
{
  intarray copy;
  int i;

  i = 0;
  copy = intarray_create(tab->len);
  while (i < tab->len)
  {
    copy->data[i] = tab->data[i];
    i++;
  }
  return (copy);
}

float intarray_average(intarray tab)
{
  int sum;

  sum = intarray_sum(tab);
  if (tab->len <= 0)
  {
    printf("intarray_sum : tableau de longueur <= 0.\n");
    return (-1);
  }
  return ((sum + 0.0) / tab->len);
}

float intarray_median(intarray tab)
{
  intarray copy;
  float result;
  int v1;
  int v2;
  if (tab->len <= 0)
  {
    printf("intarray_sum : tableau de longueur <= 0.\n");
    return (-1);
  }
  copy = intarray_clone(tab);
  intarray_sort1(copy);
  if (copy->len % 2 == 1)
  {
    result = (copy->data[(copy->len - 1) / 2]);
  }
  else
  {
    v1 = copy->data[(copy->len - 1) / 2];
    v2 = copy->data[(copy->len) / 2];
    result = ((v1 + v2) / 2.0);
  }
  intarray_destroy(copy);
  return (result);
}

void intarray_sort1(intarray tab)
{
  int i;
  int index_min;

  i = 0;
  while (i <= tab->len - 2)
  {
    index_min = intarray_get_index_of_min_from(tab, i);
    intarray_swap(tab->data + i, tab->data + index_min);
    i++;
  }
}

void intarray_set(intarray tab, int index, int value)
{
  if ((index < 0) || (index >= tab->len))
  {
    printf("intarray_set :\nL'index %d est invalide.\n", index);
    printf("Les valeurs valides sont entre 0 et %d.\n", tab->len - 1);
    return;
  }
  tab->data[index] = value;
}

void intarray_print_positive_values(intarray tab)
{
  int i;

  i = 0;
  while (i < tab->len)
  {
    if (tab->data[i] >= 0)
      printf("%d ", tab->data[i]);
    i++;
  }
}

void intarray_debug(intarray tab)
{
  int i;

  i = 0;
  printf("[ ");
  while (i < tab->len - 1)
  {
    printf("%d, ", tab->data[i]);
    i++;
  }
  if (tab->len > 0)
    printf("%d", tab->data[tab->len - 1]);
  printf(" ]");
  printf("\n");
}

void intarray_destroy(intarray tab)
{
  free(tab->data);
  free(tab);
}

void intarray_delete(intarray tab, int index)
{
  int i;

  if ((index < 0) || (index >= tab->len))
  {
    printf("intarray_delete : L'index est incorrecte.\n");
    return;
  }

  i = index + 1; // index = 2 => i = 2 + 1 => i = 3
  while (i < tab->len)
  {
    tab->data[i - 1] = tab->data[i];
    //   0   1   2   3   4
    // [22, 10, 93, 17, 14]
    // [22, 10, 17, 14]
    i++;
  }
  tab->len--;
}

void unsorted_intarray_delete(intarray tab, int index)
{
  if ((index < 0) || (index >= tab->len))
  {
    printf("intarray_delete : L'index est incorrecte.\n");
    return;
  }
  tab->data[index] = tab->data[tab->len - 1];
  tab->len--;
}

void intarray_add(intarray tab, int value)
{
  if (tab->len >= tab->alloc)
  {
    printf("intarray_add : La taille alloué n'est pas suffisante.\n");
    return;
  }
  tab->data[tab->len] = value;
  tab->len++;
}

int intarray_length(intarray tab)
{
  return tab->len;
}

int intarray_get(intarray tab, int index)
{
  if ((index < 0) || (index >= tab->len))
  {
    printf("intarray_get :\nL'index %d est invalide.\n", index);
    printf("Les valeurs valides sont entre 0 et %d.\n", tab->len - 1);
    return (-1);
  }
  return tab->data[index];
}

int intarray_search(intarray tab, int n)
{
  int i;

  i = 0;
  while (i < tab->len)
  {
    if (tab->data[i] == n)
      return (1);
    i++;
  }
  return (0);
}

int intarray_nb_occurences(intarray tab, int n)
{
  int i;
  int nb;

  nb = 0;
  i = 0;
  while (i < tab->len)
  {
    if (tab->data[i] == n)
      nb++;
    i++;
  }
  return (nb);
}

int intarray_get_min(intarray tab)
{
  int index_min = intarray_get_index_of_min(tab);
  return (tab->data[index_min]);
}

int intarray_get_max(intarray tab)
{
  int index_max = intarray_get_index_of_max(tab);
  return (tab->data[index_max]);
}

int intarray_get_index_of_min(intarray tab)
{
  return (intarray_get_index_of_min_from(tab, 0));
}

int intarray_get_index_of_max(intarray tab)
{
  return (intarray_get_index_of_max_from(tab, 0));
}

int intarray_get_index_of_min_from(intarray tab, int n)
{
  int i;
  int index;
  int min;

  if ((n < 0) || (n >= tab->len))
  {
    printf("intarray_get_index_of_min_from : l'index est invalide.\n");
    printf("Les valeurs valides sont comprise entre 0 et %d.\n", tab->len - 1);
    return (0);
  }

  i = n + 1;
  index = n;
  min = tab->data[n];
  while (i < tab->len)
  {
    if (min > tab->data[i])
    {
      min = tab->data[i];
      index = i;
    }
    i++;
  }
  return (index);
}

int intarray_get_index_of_max_from(intarray tab, int n)
{
  int i;
  int index;
  int max;

  if ((n < 0) || (n >= tab->len))
  {
    printf("intarray_get_index_of_min_from : l'index est invalide.\n");
    printf("Les valeurs valides sont comprise entre 0 et %d.\n", tab->len - 1);
    return (0);
  }

  i = n + 1;
  index = n;
  max = tab->data[n];
  while (i < tab->len)
  {
    if (max < tab->data[i])
    {
      max = tab->data[i];
      index = i;
    }
    i++;
  }
  return (index);
}

int intarray_sum(intarray tab)
{
  int sum;
  int i;

  i = 0;
  sum = 0;
  if (tab->len <= 0)
    printf("intarray_sum : tableau de longueur <= 0.\n");
  while (i < tab->len)
  {
    sum += tab->data[i];
    i++;
  }
  return (sum);
}