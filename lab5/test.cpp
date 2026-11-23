#include <iostream>
#include <cstdio>
#include <cmath>

struct Matrix {
    unsigned int m;
    unsigned int n;
    double *data = nullptr;
};

Matrix init_foo(const unsigned int M = 1, const unsigned int N = 1){
    Matrix object;
    object.data = new double[M*N];
    object.m = M;
    object.n = N;

    for (size_t i = 0; i < M*N; i++){
        object.data[i] = 0;
    }

    return object;
}

int main(){
    Matrix J = init_foo(3);
    for (size_t i = 0; i < J.m*J.n; i++){
        std::cout << "Value: " << J.data[i] << std::endl;
    }
}