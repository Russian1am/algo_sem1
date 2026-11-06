#include "other.h"
#include <iostream>
#include <cassert>
#include <cstdarg>

int inc_by_value(int value)
{
    return value + 1;
}

void inc_by_pointer(int *value)
{
    ++*value;
}

void inc_by_reference(int& value)
{
    ++value;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int& a, int& b)
{
    swap(&a, &b);
}

int min_array(const int *a, int n)
{
    assert(n > 0);
    assert(a != 0);
    int result = a[0];
    for (int i = 1; i < n; i++){    
        if (a[i] < result){
            result = a[i];
        }
    }
    return result;
}

int min_array(const int *const *a, int rows, int cols)
{
    assert(rows > 0 && cols > 0);
    assert(a != 0);
    int result = min_array(a[0], cols);
    for (int i = 1; i < rows; i++) {
        int value = min_array(a[i], cols);
        if (value < result){
            result = value;
        }
    }
    return result;
}

int my_str_cmp(const char *a, const char *b)
{
    while (*a != '\0' && *a == *b) {
        ++a;
        ++b;
    }
    return (unsigned char)*a - (unsigned char)*b;
}

int day_of_year(int day, int month, int year, const int (*table)[12])
{
    int leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    for (int i = 0; i < month - 1; i++){
        day += table[leap][i];
    }
    return day;
}

void day_of_month(int year, int number, int &day, int &month, const int (*table)[12])
{
    int leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    month = 1;
    while (number > table[leap][month - 1]) {
        number -= table[leap][month - 1];
        ++month;
    }
    day = number;
}

void add_unique(int*& arr, size_t& size, int new_value, size_t& amount_of_digits){
    for (size_t i = 0; i < amount_of_digits; i++){
        if (arr[i] == new_value){
            return;
        }
    }

    if (amount_of_digits >= size){
        size *= 2;
        int *b = new int[size];
        for (size_t i = 0; i < amount_of_digits; i++){
            b[i] = arr[i];
        }
        b[amount_of_digits] = new_value;
        delete[] arr;
        arr = b;
    }
    else{
        arr[amount_of_digits] = new_value;
    }
    amount_of_digits++;  
}

void print_array1(const int* arr, const int size, const int amount_of_digits){
    std::cout << "==================================|" <<std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Elements: " << amount_of_digits << std::endl;
    std::cout << "Free space: " << size-amount_of_digits << std::endl;
    std::cout << "---------------------------------" << std::endl;
    for (size_t i = 0; i < amount_of_digits; i++){
        std::cout << "| " << i << " - " << arr[i] << " |" << std::endl;
    }
    std::cout << "==================================|" <<std::endl;

}

void print_array(const int *a, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int natural_sum(int n)
{
    if (n <= 0) {
        return 0;
    }
    return n + natural_sum(n - 1);
}

int encoded32_size(int raw_size)
{
    if (raw_size < 0 || raw_size > 268435455) {
        return -1;
    }
    return (raw_size * 8 + 4) / 5;
}

int decoded32_size(int encoded_size)
{
    if (encoded_size < 0) {
        return -1;
    }
    return encoded_size / 8 * 5 + encoded_size % 8 * 5 / 8;
}

int encode32(const char *raw_data, int raw_size, char *dst)
{
    int size = encoded32_size(raw_size);
    if (size < 0 || raw_data == 0 || dst == 0) {
        return 1;
    }
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456";
    for (int i = 0; i < size; i++) {
        int value = 0;
        for (int j = 0; j < 5; ++j) {
            int bit = i * 5 + j;
            value <<= 1;
            if (bit < raw_size * 8) {
                value |= ((unsigned char)raw_data[bit / 8] >> (7 - bit % 8)) & 1;
            }
        }
        dst[i] = table[value];
    }
    return 0;
}

int decode32(const char *encoded_data, int encoded_size, char *dst)
{
    int size = decoded32_size(encoded_size);
    if (size < 0 || encoded_data == 0 || dst == 0 ||
        encoded32_size(size) != encoded_size) {
        return 1;
    }
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456";
    int buffer = 0, bits = 0, position = 0;
    for (int i = 0; i < encoded_size; i++) {
        int value = 0;
        while (value < 32 && table[value] != encoded_data[i]) {
            ++value;
        }
        if (value == 32) {
            return 2;
        }
        buffer = (buffer << 5) | value;
        bits += 5;
        if (bits >= 8) {
            bits -= 8;
            dst[position++] = (char)(buffer >> bits);
            buffer &= (1 << bits) - 1;
        }
    }
    if (buffer != 0) {
        return 1;
    }
    return 0;
}

void var_args(int first, ...)
{
    va_list args;
    va_start(args, first);
    int count = 0;
    for (int value = first; value != 0; value = va_arg(args, int)) {
        ++count;
    }
    va_end(args);
    std::cout << count << ": ";
    va_start(args, first);
    for (int value = first; value != 0; value = va_arg(args, int)) {
        std::cout << value << " ";
    }
    va_end(args);
    std::cout << "\n";
}

int *my_min(int *a, int n)
{
    assert(n > 0 && a != nullptr); // nullptr вместо 0
    int *result = a;
    for (int i = 1; i < n; i++) {
        if (a[i] < *result) {
            result = a + i;
        }
    }
    return result;
}
