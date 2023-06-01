//2022/08/16 07:33:36
//2022/08/16 07:47:05 AC.
//ABC087_C - Candies
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, A[100][100], sum[2] = {0};
    cin >> N;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            sum[i] += A[i][j];
        }
    }
    int num = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        num += A[0][i];
        if (max < num + sum[1]) {
            max = num + sum[1];
        }
        sum[1] -= A[1][i];
    }
    cout << max << endl;
    return 0;
}