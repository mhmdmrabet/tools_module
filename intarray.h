typedef struct intarray intarray;

struct intarray{
  int *data;
  int len;
};


intarray  intarray_create(int len);
intarray  intarray_concat(intarray tab1, intarray tab2);
void      intarray_destroy(intarray tab);
void      intarray_print_positive_values(intarray tab);
void      intarray_debug(intarray tab);
void      intarray_sort1(intarray tab);
void      intarray_set(intarray tab, int index, int value);
void      intarray_swap(int *first, int *second);
int       intarray_length(intarray tab);
int       intarray_search(intarray tab, int n);
int       intarray_nb_occurences(intarray tab, int n);
int       intarray_get(intarray tab, int index);
int       intarray_get_min(intarray tab);
int       intarray_get_index_of_min(intarray tab);
int       intarray_get_index_of_min_from(intarray tab, int n);