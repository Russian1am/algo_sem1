#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[3][3][3] = {{{},{},{}}, {{},{},{}}, {{},{},{}}};
    int user_input = 0, sum_of_digits = 0;
    for (int i = 0;i < 3; i++){
        cout << "\nLayer number " << i + 1 << endl;
        for (int k = 0; k < 3; k++){
            for (int j = 0; j < 3; j++){
                cout << "Enter number: ";
                cin >> arr[i][k][j];
            }
        }
    }
    for (int i = 0;i < 3; i++){
        for (int k = 0; k < 3; k++){
            for (int j = 0; j < 3; j++){
                sum_of_digits += arr[i][k][j];
            }
        }
    }
    cout << "The sum is: " << sum_of_digits << endl;
}