#include <iostream>
#include <vector>
using namespace std;

int rand_gen(int n){
    return (rand() % n);
}

int main(){
    int (*arr)[2] = new int[2][rand_gen(10)];

    for(int i = 0; i < 2; i++){
        for(int k = 0; k < y; k++){
            arr[i][k] = rand_gen(15);
        }
    }

    for(int i = 0; i < 2; i++){
        cout << endl;
        for(int k = 0; k < y; k++){
            cout << arr[i][k] << endl;
        }
    }
}