//2022/08/06 21:20:47
//2022/08/06 22:20:52
#include <iostream>
using namespace std;
void printArray(int *arr, int N){
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }    
}
void func(int *a, int *arr, int N, int M){
    if (*(a + 1) <= *a) {
        *(a + 1) = (*a) + 1;
        func(a + 1, arr, N, M);
    }
    if (M < *a) {
        *a = 0;
        return;
    } else if (*(a + 1) != 0) {
        printArray(arr, N);
    }
    (*a)++;
    func(a, arr, N, M);
}
int main(){
    int N, M, arr[11] = {0};
    cin >> N >> M;
    arr[0] = 1;
    arr[N] = 25;
    func(arr, arr, N, M);
    return 0;
}