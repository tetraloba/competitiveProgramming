//2022/08/11 16:40:42
//2022/08/11 17:08:31 AC. 無駄に関数を分割するなど。
#include <iostream>
#include <vector>
using namespace std;
void input(vector<int>&, int);
bool find(vector<int>, int);
int main(){
    int N, V;
    cin >> N >> V;
    vector<int> A;
    input(A, N);
    if (find(A, V)){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
void input(vector<int>& A, int N){
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.insert(A.end(), tmp);
    }
}
bool find(vector<int> A, int V){
    for (int i : A) {
        if (i == V) {
            return true;
        }
    }
    return false;
}