#ifndef LAB4_OTHER_H
#define LAB4_OTHER_H

int inc_by_value(int value);
void inc_by_pointer(int *value);
void inc_by_reference(int &value);
void swap(int *a, int *b);
void swap(int &a, int &b);
int min_array(const int *a, int n);
int min_array(const int *const *a, int rows, int columns);
int my_str_cmp(const char *a, const char *b);
int day_of_year(int day, int month, int year, const int (*table)[12]);
void day_of_month(int year, int number, int &day, int &month, const int (*table)[12]);
void add_unique(int *&a, int &n, int value);
void print_array1(const int* arr, const int size, const int amount_of_digits);
void print_array(const int *a, int n);
int natural_sum(int n);
int encoded32_size(int raw_size);
int decoded32_size(int encoded_size);
int encode32(const char *raw_data, int raw_size, char *dst);
int decode32(const char *encoded_data, int encoded_size, char *dst);
void var_args(int first, ...);
#define VAR_ARGS(...) var_args(__VA_ARGS__, 0)
int *my_min(int *a, int n);

#endif
