// 2023/11/04 16:54:43
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int>> A(1, vector<int>(0)), B(1, vector<int>(1));
    cout << (A == B) << endl;
    return 0;
}