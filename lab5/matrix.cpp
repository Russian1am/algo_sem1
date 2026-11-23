#include "matrix.h"

Matrix init_foo(const unsigned int M, const unsigned int N){
    Matrix object;
    object.data = new double[M*N];
    object.m = M;
    object.n = N;

    for (size_t i = 0; i < M*N; i++){
        object.data[i] = 0;
    }

    return object;
}

void m_free(Matrix *A){
    delete[] A->data;
    A->data = 0;
    A->m = 0;
    A->n = 0;
}

void m_zero(Matrix *A, int m_val, int n_val){
    if (A->data == nullptr){
        A = init_foo(m_val, n_val);
        return;
    }

    if (m_val*n_val > A->m*A->n){
        m_free(A);
        A->m = m_val;
        A->n = n_val;
        A->data = new double[m_val * n_val];
    }

    for (size_t i = 0; i < m_val*n_val; i++){
        A->data[i] = 0;
    }
}

void m_id(Matrix *A, int n){
    m_zero(A, n, n);
    for (int i = 0; i < n; ++i){
        A->data[i * n + i] = 1;
    }
}

void m_copy(const Matrix *src, Matrix *dst){
    if (src == dst){
        return;
    }
    m_zero(dst, src->m, src->n);
    for (int i = 0; i < src->m * src->n; ++i){
        dst->data[i] = src->data[i];
    }
}

int m_width(const Matrix *A){
    return A->n;
}

int m_height(const Matrix *A){
    return A->m;
}

double m_get(const Matrix *A, int i, int j){
    return A->data[i * A->n + j];
}

void m_set(Matrix *A, int i, int j, double value){
    A->data[i * A->n + j] = value;
}

int m_add(Matrix *A, const Matrix *B){
    if (A->m != B->m || A->n != B->n){
        return 1;
    }
    for (int i = 0; i < A->m * A->n; ++i){
        A->data[i] += B->data[i];
    }
    return 0;
}

void m_neg(Matrix *A){
    for (int i = 0; i < A->m * A->n; ++i){
        A->data[i] = -A->data[i];
    }
}

int m_mult(const Matrix *A, const Matrix *B, Matrix *dst){
    if (A->n != B->m){
        return 1;
    }
    Matrix result = init_foo(3);
    result = {0, 0, 0};
    m_zero(&result, A->m, B->n);
    for (int i = 0; i < A->m; ++i){
        for (int j = 0; j < B->n; ++j){
            for (int k = 0; k < A->n; ++k){
                result.data[i * result.n + j] += A->data[i * A->n + k] * B->data[k * B->n + j];
            }
        }
    }
    m_free(dst);
    *dst = result;
    return 0;
}
