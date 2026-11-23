#include "other.h"
#include <iostream>
#include <cstdio>
#include <cmath>



void sort(char* pcFirst, int nNumber, int size, void (*Swap)(void*, void*), int (*Compare)(void*, void*) ){
    int i;
    for(i=1; i<nNumber; i++){
        for(int j=nNumber-1; j>=i; j--){
            char* pCurrent = pcFirst+j*size;
            char* pPrevious = pcFirst+(j-1)*size;
            if((*Compare)( pPrevious, pCurrent ) > 0){
                (*Swap)( pPrevious, pCurrent );
            }
        }
    }
}

void swap_int(void* p1, void* p2){
    int temp = *(int*)p1;
    *(int*)p1 = *(int*)p2;
    *(int*)p2 = temp;
}

int cmp_int(void* p1, void* p2){
    int a = *(int*)p1, b = *(int*)p2;
    int nResult = (a > b) - (a < b);
    return nResult;
}

bool finish_line(){
    bool valid = true;
    int c;
    while ((c = std::getchar()) != '\n' && c != EOF){
        if (c != ' ' && c != '\t' && c != '\r'){
            valid = false;
        }
    }
    return valid;
}

bool read_number(const char *prompt, double &value){
    while (true){
        std::printf("%s", prompt);
        int result = std::scanf("%lf", &value);
        if (result == EOF){
            return false;
        }
        bool clean = finish_line();
        if (result == 1 && clean && value - value == 0){
            return true;
        }
        std::printf("Введите корректное число.\n");
    }
}

bool read_integer(const char *prompt, int low, int high, int &value){
    double number;
    while (read_number(prompt, number)){
        if (number >= low && number <= high && number == (int)number){
            value = (int)number;
            return true;
        }
        std::printf("Введите целое число от %d до %d.\n", low, high);
    }
    return false;
}

double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}

double div(double a, double b){
    return a / b;
}

// высчитывание pow(e, x),e=const при помощи ряда тейлора
double my_exp(double x){
    double result = 1.0;
    double term = 1.0;

    for (int i = 1; i <= 30; i++){
        term *= x / i;
        result += term;
    }

    return result;
}

double my_sin(double x){
    double result = x, term = x;
    for (int i = 1; i <= 20; ++i){
        term *= -x * x / ((2 * i) * (2 * i + 1));
        result += term;
    }
    return result;
}

double power(double a, double b){
    return std::pow(a, b);
}

void swap_double(void *a, void *b){
    double temp = *(double*)a;
    *(double*)a = *(double*)b;
    *(double*)b = temp;
}

int cmp_double(void *a, void *b){
    double x = *(double*)a, y = *(double*)b;
    return (x > y) - (x < y);
}

void swap_str(void *a, void *b){
    const char *temp = *(const char**)a;
    *(const char**)a = *(const char**)b;
    *(const char**)b = temp;
}

int cmp_str(void *a, void *b){
    const char *x = *(const char**)a, *y = *(const char**)b;
    while (*x != '\0' && *x == *y){
        ++x;
        ++y;
    }
    return (unsigned char)*x - (unsigned char)*y;
}

void print_array(const int *a, int n){
    for (int i = 0; i < n; ++i){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void print_max(int *a, int n){
    int result = a[0];
    for (int i = 1; i < n; ++i){
        if (a[i] > result){
            result = a[i];
        }
    }
    std::cout << result << "\n";
}

void print_min(int *a, int n){
    int result = a[0];
    for (int i = 1; i < n; ++i){
        if (a[i] < result){
            result = a[i];
        }
    }
    std::cout << result << "\n";
}

void sort_asc(int *a, int n){
    sort((char*)a, n, sizeof(int), swap_int, cmp_int);
    print_array(a, n);
}

void sort_desc(int *a, int n){
    sort((char*)a, n, sizeof(int), swap_int, cmp_int);
    for (int i = 0; i < n / 2; ++i){
        swap_int(a + i, a + n - 1 - i);
    }
    print_array(a, n);
}

double integrate(double (*function)(double), double low, double high, int n){
    if (n <= 0 || function == 0){
        return 0;
    }
    double step = (high - low) / n;
    double result = 0;
    for (int i = 0; i < n; ++i){
        result += function(low + (i + 0.5) * step);
    }
    return result * step;
}

double linear(double x){
    return 2 * x + 1;
}

double square(double x){
    return x * x;
}

void copy_text(char *dst, const char *src, int capacity){
    int i = 0;
    while (i < capacity - 1 && src[i] != '\0'){
        dst[i] = src[i];
        ++i;
    }
    dst[i] = '\0';
}

void set_book(Book &book, const char *author, const char *title, int year, double price, int category){
    copy_text(book.author, author, 128);
    copy_text(book.title, title, 128);
    book.year = year;
    book.price = price;
    book.category = category;
}

void print_book(const Book &book){
    const char *categories[3] = {"Художественная", "Научная", "Учебная"};
    std::printf("Автор: %s\nНазвание: %s\nГод: %d\nЦена: %.2f\nКатегория: %s\n\n",
                book.author, book.title, book.year, book.price, categories[book.category - 1]);
}

bool read_text(const char *prompt, char *text){
    while (true){
        std::printf("%s", prompt);
        int result = std::scanf("%127[^\n]", text);
        if (result == EOF){
            return false;
        }
        int c = std::getchar();
        if (result == 1 && (c == '\n' || c == EOF)){
            return true;
        }
        if (c != '\n' && c != EOF){
            finish_line();
        }
        std::printf("Введите от 1 до 127 байт текста.\n");
    }
}

bool read_book(Book &book){
    if (!read_text("Автор: ", book.author) || !read_text("Название: ", book.title)){
        return false;
    }
    if (!read_integer("Год (-3500..2026): ", -3500, 2026, book.year)){
        return false;
    }
    while (true){
        if (!read_number("Цена: ", book.price)){
            return false;
        }
        if (book.price >= 0){
            break;
        }
        std::printf("Цена не может быть отрицательной.\n");
    }
    return read_integer("Категория (1 — художественная, 2 — научная, 3 — учебная): ", 1, 3, book.category);
}


