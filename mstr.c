#include <stdio.h>
#include <stdlib.h>

#include "mstr.h"
#include "tools.h"

void mstr_create_aux(mstr tab)
{
  int i;
  if (tab->alloc <= 0)
  {
    tab->alloc = 4;
    printf("mstr_create_aux : taille allouée <= 0.\nNous allouons %d à la place.\n", tab->alloc);
  }
  i = 0;
  tab->data = malloc(tab->alloc * sizeof(char));
  while (i < tab->alloc)
  {
    tab->data[i] = 0;
    i++;
  }
}

mstr mstr_create(int len)
{
  mstr tab;
  tab = malloc(sizeof(struct _mstr));
  tab->len = len;
  tab->alloc = len;
  mstr_create_aux(tab);
  return (tab);
}

mstr empty_mstr_create(int alloc)
{
  mstr tab;

  tab = malloc(sizeof(struct _mstr));
  tab->len = 0;
  tab->alloc = alloc;
  mstr_create_aux(tab);
  return (tab);
}

mstr standard_empty_mstr_create(void)
{
  return empty_mstr_create(MSTR_DEFAULT_ALLOC);
}

mstr mstr_concat(mstr tab1, mstr tab2)
{
  mstr tab;
  int len;
  int i;
  int j;

  i = 0;
  j = 0;
  len = tab1->len + tab2->len;
  tab = mstr_create(len);
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

mstr mstr_clone(mstr tab)
{
  mstr copy;
  int i;

  i = 0;
  copy = mstr_create(tab->len);
  while (i < tab->len)
  {
    copy->data[i] = tab->data[i];
    i++;
  }
  return (copy);
}

void mstr_resize(mstr tab, int size)
{
  char *new_tab;
  int i;

  i = 0;
  new_tab = malloc(sizeof(char) * size);
  while (i < tab->len)
  {
    new_tab[i] = tab->data[i];
    i++;
  }
  free(tab->data);
  tab->data = new_tab;
  tab->alloc = size;
}

void ext_mstr_set(mstr tab, int index, char value)
{
  int i;

  i = tab->len;
  if (index < 0)
  {
    printf("ext_mstr_set : impossible d'écrire en case %d.\n", index);
    return;
  }
  if (index < tab->len)
  {
    tab->data[index] = value;
    ext_mstr_debug(tab);
    return;
  }
  if (index >= tab->alloc)
  {
    mstr_resize(tab, 1 + 2 * index);
  }
  while (i < index)
  {
    tab->data[i] = 0;
    i++;
  }
  tab->data[index] = value;
  if (index >= tab->len)
  {
    tab->len = index + 1;
  }
}

void mstr_set(mstr tab, int index, char value)
{
  if ((index < 0) || (index >= tab->len))
  {
    printf("mstr_set :\nL'index %d est invalide.\n", index);
    printf("Les valeurs valides sont entre 0 et %d.\n", tab->len - 1);
    return;
  }
  tab->data[index] = value;
}

void mstr_print_positive_values(mstr tab)
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

void mstr_debug(mstr tab)
{
  int i;

  i = 0;
  while (i < tab->len)
  {
    printf("%c", tab->data[i]);
    i++;
  }
  printf("\n");
}

void ext_mstr_debug(mstr tab)
{
  printf("Tab. alloc = %d ; len = %d\n", tab->alloc, tab->len);
  mstr_debug(tab);
}

void mstr_destroy(mstr tab)
{
  free(tab->data);
  free(tab);
}

void mstr_delete(mstr tab, int index)
{
  int i;

  if ((index < 0) || (index >= tab->len))
  {
    printf("mstr_delete : L'index est incorrecte.\n");
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

void unsorted_mstr_delete(mstr tab, int index)
{
  if ((index < 0) || (index >= tab->len))
  {
    printf("mstr_delete : L'index est incorrecte.\n");
    return;
  }
  tab->data[index] = tab->data[tab->len - 1];
  tab->len--;
}

void mstr_add(mstr tab, char value)
{
  ext_mstr_set(tab, tab->len, value);
}

int mstr_length(mstr tab)
{
  return tab->len;
}

char mstr_get(mstr tab, int index)
{
  if ((index < 0) || (index >= tab->len))
  {
    printf("mstr_get :\nL'index %d est invalide.\n", index);
    printf("Les valeurs valides sont entre 0 et %d.\n", tab->len - 1);
    return (-1);
  }
  return tab->data[index];
}

int mstr_search(mstr tab, char n)
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

int mstr_nb_occurences(mstr tab, char n)
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

char mstr_get_min(mstr tab)
{
  int index_min = mstr_get_index_of_min(tab);
  return (tab->data[index_min]);
}

char mstr_get_max(mstr tab)
{
  int index_max = mstr_get_index_of_max(tab);
  return (tab->data[index_max]);
}

int mstr_get_index_of_min(mstr tab)
{
  return (mstr_get_index_of_min_from(tab, 0));
}

int mstr_get_index_of_max(mstr tab)
{
  return (mstr_get_index_of_max_from(tab, 0));
}

int mstr_get_index_of_min_from(mstr tab, int n)
{
  int i;
  int index;
  char min;

  if ((n < 0) || (n >= tab->len))
  {
    printf("mstr_get_index_of_min_from : l'index est invalide.\n");
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

int mstr_get_index_of_max_from(mstr tab, int n)
{
  int i;
  int index;
  char max;

  if ((n < 0) || (n >= tab->len))
  {
    printf("mstr_get_index_of_max_from : l'index est invalide.\n");
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

mstr regstr_to_mstr(char *str)
{
  int i;
  mstr tab;

  tab = standard_empty_mstr_create();
  i = 0;
  while (str[i])
  {
    mstr_add(tab, str[i]);
    i++;
  }
  return (tab);
}

char *mstr_to_regstr(mstr tab)
{
  int i;
  char *str;

  str = malloc(sizeof(char) * (tab->len + 1));
  i = 0;
  while (i < tab->len)
  {
    str[i] = tab->data[i];
    i++;
  }
  str[tab->len] = '\0';
  return (str);
}