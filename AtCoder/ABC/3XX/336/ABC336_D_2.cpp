// 2024/02/24 18:29:44
// 2024/02/24 18:39:09 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a: A) cin >> a;
    A[0] = min(A[0], 1); A[N - 1] = min(A[N - 1], 1); // 左端, 右端
    for (int i = 0; i < N - 1; i++) A[i + 1] = min(A[i + 1], A[i] + 1); // 左 to 右
    for (int i = N - 1; 1 <= i; i--) A[i - 1] = min(A[i - 1], A[i] + 1); // 右 to 左
    cout << *max_element(A.begin(), A.end()) << endl;
    return 0;
}