// 2024/07/05 17:31:15
// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int diff(int a, int b){
    return a < b ? b - a : a - b;
}
int main(){
    vector<int> v;
    cout << (v.begin() == v.end() ? "Yes" : "No") << endl;
    return 0;
}