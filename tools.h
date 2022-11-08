#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include <stdlib.h>

void intarray_swap(int *first, int *second);
void char_swap(char *first, char *second);
int string_to_int(char *str);
int safe_string_to_int(char *str, int *ok);

#endif