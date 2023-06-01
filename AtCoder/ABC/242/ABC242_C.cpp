//2022/08/13 20:30:02
//2022/08/13 20:55:55 AC.
#include <iostream>
#include <vector>
#define NUM 998244353
// #define NUM 200
using namespace std;
int main(){
    int N;
    cin >> N;
    unsigned long long int arr1[11] = {0}, arr2[11] = {0};
    for (int i = 1; i <= 9; i++) {
        arr1[i] = arr2[i] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 1; j <= 9; j++) {
            arr2[j] = arr1[j - 1] + arr1[j] + arr1[j + 1];
        }
        if (NUM <= arr2[5]) {
            for (int j = 1; j <= 9; j++) {
                arr2[j] %= NUM;
            }
        }
        for (int j = 1; j <= 9; j++) {
            // cout << arr1[j] << ' ' << arr2[j] << endl;
            arr1[j] = arr2[j];
        }
    }
    unsigned long long int sum = 0;
    for (int i = 1; i <= 9; i++) {
        sum += arr2[i];
        if (NUM <= sum) {
            sum %= NUM;
        }
    }
    cout << sum << endl;
    return 0;
}