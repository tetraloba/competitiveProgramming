//2022/08/29 07:30:04
//2022/08/29 07:33:19 AC.
//ABC053_B A to Z string
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int posA = s.find('A');
    int posZ = s.rfind('Z');
    cout << posZ - posA + 1 << endl;
    return 0;
}