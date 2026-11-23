#ifndef LAB5_OTHER_H
#define LAB5_OTHER_H

//Прототипы используемых в данном задании функций:

void sort(char* pcFirst, int nNumber, int size,
     void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void swap_int(void* p1, void* p2);
int cmp_int(void* p1, void* p2);

bool finish_line();
bool read_number(const char *prompt, double &value);
bool read_integer(const char *prompt, int low, int high, int &value);
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);
double power(double a, double b);
double my_exp(double x);
double my_sin(double x);
void swap_double(void *a, void *b);
int cmp_double(void *a, void *b);
void swap_str(void *a, void *b);
int cmp_str(void *a, void *b);
void print_array(const int *a, int n);
void print_max(int *a, int n);
void print_min(int *a, int n);
void sort_asc(int *a, int n);
void sort_desc(int *a, int n);
double integrate(double (*function)(double), double low, double high, int n);
double linear(double x);
double square(double x);
struct Book {
    char author[128];
    char title[128];
    int year;
    double price;
    int category;
};
void set_book(Book &book, const char *author, const char *title, int year, double price, int category);
void print_book(const Book &book);
bool read_book(Book &book);

#endif
