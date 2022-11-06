#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

void intarray_swap(int *first, int *second)
{
  int tmp;

  tmp = *first;
  *first = *second;
  *second = tmp;
}

void char_swap(char *first, char *second)
{
  char tmp;

  tmp = *first;
  *first = *second;
  *second = tmp;
}

int string_to_int(char *str)
{
  int ok;
  int result;

  result = safe_string_to_int(str, &ok);
  if (ok == 0)
    printf("Une erreur a été rencontrée.\n");
  return (result);
}

int safe_string_to_int(char *str, int *ok)
{
  int result;
  int i;

  if (str[0] == '-')
    return -safe_string_to_int(str + 1, ok);

  result = 0;
  i = 0;
  *ok = 1;
  if (str[0] == '\0')
  {
    *ok = 0;
    return (0);
  }
  while (str[i])
  {
    if ((str[i] < '0') || (str[i] > '9'))
    {
      *ok = 0;
      return (0);
    }
    result *= 10;
    result += (str[i] - 48);
    i++;
  }
  return (result);
}
