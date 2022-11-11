#include <stdio.h>
#include <stdlib.h>
#include "intarray.h"
#include "tools.h"
#include "mstr.h"

int main(void)
{
	mstr	str1;
	mstr	str2;
	
	str1 = regstr_to_mstr("tototo tititototi");
	str2 = regstr_to_mstr("toto");
	intarray	A = mstr_find_proper_substr_indices(str1, str2);
	intarray_debug(A);
	intarray_destroy(A);
	mstr_destroy(str1);
	mstr_destroy(str2);
  	return (0);
}