//2022/08/12 07:30:13
//2022/08/12 07:33:16 AC.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int N;
    cin >> N;
    cout.fill('0');
    cout << setw(2) << N % 100 << endl;
    return 0;
}