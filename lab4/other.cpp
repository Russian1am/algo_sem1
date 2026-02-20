#include "other.h"
#include <iostream>
#include <cassert>
#include <cstdarg>
#include <cstring>

int inc_by_value(int val) {
    int tmp = val;
    tmp = tmp + 1;
    return tmp;
}

void inc_by_pointer(int* ptr) {
    if (ptr) {
        int v = *ptr;
        v = v + 1;
        *ptr = v;
    }
}

void inc_by_reference(int& ref) {
    int copy = ref;
    copy += 1;
    ref = copy;
}

void swap(int* X, int* Y) {
    if (X && Y && X != Y) {
        int a = *X;
        int b = *Y;
        *X = b;
        *Y = a;
    }
}

void swap(int& X, int& Y) {
    if (&X != &Y) {
        int t1 = X;
        int t2 = Y;
        X = t2;
        Y = t1;
    }
}

int find_min(int* const arr, int size) {
    assert(arr != nullptr);
    assert(size > 0);
    int index = 0;
    int i = 1;
    while (i < size) {
        if (arr[i] < arr[index]) {
            index = i;
        }
        ++i;
    }
    return arr[index];
}

int find_min2(int** const matrix, int rows, int cols) {
    assert(matrix != nullptr);
    int result = find_min(matrix[0], cols);
    for (int r = 1; r < rows; ++r) {
        int candidate = find_min(matrix[r], cols);
        if (!(candidate >= result)) {
            result = candidate;
        }
    }
    return result;
}

int my_str_cmp(const char* const s1, const char* const s2) {
    const unsigned char* p1 = (const unsigned char*)s1;
    const unsigned char* p2 = (const unsigned char*)s2;
    while (*p1 && *p2) {
        if (*p1 != *p2) break;
        ++p1;
        ++p2;
    }
    return (int)(*p1) - (int)(*p2);
}

int day_of_year(int day, int month, int year, int (*nDayTab)[12]) {
    int leap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        leap = 1;
    }
    int total = 0;
    for (int i = 0; i < month - 1; ++i) {
        total += nDayTab[leap][i];
    }
    total += day;
    return total;
}

void day_of_month(int days, int year, int& day, int& month, int (*nDayTab)[12]) {
    int leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;
    int m = 0;
    while (m < 12 && days > nDayTab[leap][m]) {
        days -= nDayTab[leap][m];
        ++m;
    }
    month = m + 1;
    day = days;
}

void print_array(int* const arr, int size) {
    if (!arr || size <= 0) return;
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void add_unique(int*& arr, int& size, int value) {
    bool exists = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            exists = true;
        }
    }
    if (exists) return;

    int newSize = size + 1;
    int* temp = new int[newSize];
    for (int i = 0; i < size; ++i) {
        temp[i] = arr[i];
    }
    temp[newSize - 1] = value;
    delete[] arr;
    arr = temp;
    size = newSize;
}

int natural_sum(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return n + natural_sum(n - 1);
}

void var_args(int first, ...) {
    int count = 0;
    va_list args;
    va_start(args, first);

    int current = first;
    if (current != 0) {
        count++;
        while ((current = va_arg(args, int)) != 0) {
            count++;
        }
    }
    va_end(args);

    std::cout << count << " : ";

    va_start(args, first);
    current = first;
    if (current != 0) {
        cout << current;
        while ((current = va_arg(args, int)) != 0) {
            cout << " " << current;
        }
    }
    va_end(args);
    cout << endl;
}

int encoded32_size(int raw_size) {
    int bits = raw_size * 8;
    int result = bits / 5;
    if (bits % 5 != 0) result++;
    return result;
}

int decoded32_size(int encode_size) {
    int bits = encode_size * 5;
    return bits / 8;
}

const char* CODETABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456";

int encode32(const char* raw_data, int raw_size, char* dst) {
    if (!raw_data || !dst || raw_size < 0) return 1;

    int buffer = 0;
    int bits = 0;
    int pos = 0;

    for (int i = 0; i < raw_size; ++i) {
        buffer = (buffer << 8) | (unsigned char)raw_data[i];
        bits += 8;
        while (bits >= 5) {
            int idx = (buffer >> (bits - 5)) & 31;
            dst[pos++] = CODETABLE[idx];
            bits -= 5;
        }
    }

    if (bits > 0) {
        int idx = (buffer << (5 - bits)) & 31;
        dst[pos++] = CODETABLE[idx];
    }

    dst[pos] = '\0';
    return 0;
}

char findincodetable(char c) {
    const char* p = std::strchr(CODETABLE, c);
    if (!p) return -1;
    return static_cast<char>(p - CODETABLE);
}

int decode32(const char* encoded_data, int encoded_size, char* dst) {
    if (!encoded_data || !dst || encoded_size < 0) return 1;

    int buffer = 0;
    int bits = 0;
    int pos = 0;

    for (int i = 0; i < encoded_size; ++i) {
        char val = findincodetable(encoded_data[i]);
        if (val < 0) continue;
        buffer = (buffer << 5) | val;
        bits += 5;

        if (bits >= 8) {
            dst[pos++] = (buffer >> (bits - 8)) & 255;
            bits -= 8;
        }
    }

    dst[pos] = '\0';
    return 0;
}

int* my_min(int* arr, int size) {
    assert(arr != nullptr);
    assert(size > 0);

    int* p = arr;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) < *p) {
            p = arr + i;
        }
    }
    return p;
}
