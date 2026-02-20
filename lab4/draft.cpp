#include <iostream>
using namespace std;

int main(){
    char c = 'a';
    char* pc = &c;
    char& ref_pc = pc;
    *ref = 'd';
    char b = 'g';
    ref = &b;
}