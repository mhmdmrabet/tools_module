#ifndef __MSTR_H__
#define __MSTR_H__

#include "intarray.h"
#include "tools.h"

typedef struct _mstr *mstr;
typedef struct _mstr S_mstr;

struct _mstr
{
	char *data;
	int alloc;
	int len;
};

#define MSTR_DEFAULT_ALLOC 22

intarray	mstr_find_proper_substr_indices(mstr str, mstr sub);	
intarray	mstr_find_substr_indices(mstr str, mstr sub);
mstr mstr_create(int len);
mstr empty_mstr_create(int alloc);
mstr standard_empty_mstr_create(void);
mstr mstr_clone(mstr tab);
mstr mstr_concat(mstr tab1, mstr tab2);
mstr regstr_to_mstr(char *str);
void D_mstr_concat(mstr tab1, mstr tab2);
void ext_mstr_set(mstr tab, int index, char value);
void mstr_resize(mstr tab, int size);
void mstr_destroy(mstr tab);
void mstr_print_positive_values(mstr tab);
void ext_mstr_debug(mstr tab);
void mstr_debug(mstr tab);
void mstr_set(mstr tab, int index, char value);
void unsorted_mstr_delete(mstr tab, int index);
void mstr_delete(mstr tab, int index);
void mstr_add(mstr tab, char value);
char *mstr_to_regstr(mstr tab);
char mstr_get(mstr tab, int index);
char mstr_get_min(mstr tab);
char mstr_get_max(mstr tab);
int mstr_length(mstr tab);
int mstr_search(mstr tab, char value);
int mstr_nb_occurences(mstr tab, char value);
int mstr_get_index_of_min(mstr tab);
int mstr_get_index_of_min_from(mstr tab, int index);
int mstr_get_index_of_max(mstr tab);
int mstr_get_index_of_max_from(mstr tab, int index);
int mstr_equal_substr(mstr str1, int s1, int e1, mstr str2, int s2);
int	mstr_equal(mstr str1, mstr str2);
int	mstr_compare(mstr str1, mstr str2);

#endif