typedef struct _intarray *intarray;
typedef struct _intarray S_intarray;

struct _intarray
{
  int *data;
  int alloc;
  int len;
};

#define INTARRAY_DEFAULT_ALLOC 22

intarray intarray_create(int len);
intarray empty_intarray_create(int alloc);
intarray standard_empty_intarray_create(void);
intarray intarray_clone(intarray tab);
intarray intarray_concat(intarray tab1, intarray tab2);
float intarray_average(intarray tab);
float intarray_median(intarray tab);
void ext_intarray_set(intarray tab, int index, int value);
void intarray_resize(intarray tab, int size);
void intarray_destroy(intarray tab);
void intarray_print_positive_values(intarray tab);
void ext_intarray_debug(intarray tab);
void intarray_debug(intarray tab);
void intarray_sort1(intarray tab);
void intarray_set(intarray tab, int index, int value);
void unsorted_intarray_delete(intarray tab, int index);
void intarray_delete(intarray tab, int index);
void intarray_add(intarray tab, int value);
int intarray_sum(intarray tab);
int intarray_length(intarray tab);
int intarray_search(intarray tab, int n);
int intarray_nb_occurences(intarray tab, int n);
int intarray_get(intarray tab, int index);
int intarray_get_min(intarray tab);
int intarray_get_max(intarray tab);
int intarray_get_index_of_min(intarray tab);
int intarray_get_index_of_min_from(intarray tab, int n);
int intarray_get_index_of_max(intarray tab);
int intarray_get_index_of_max_from(intarray tab, int n);