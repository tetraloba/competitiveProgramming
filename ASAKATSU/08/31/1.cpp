//2022/08/31 07:30:06
//2022/08/31 07:30:36 AC.
//ABC011_A - 来月は何月？
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    cout << (N != 12 ? N + 1 : 1) << endl;
    return 0;
}