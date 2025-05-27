// 2023/10/30 11:41:03
// 
#include <iostream>
#include <vector>
using namespace std;
struct S{
    int a;
    int b;
};
int main(){
    S s;
    s = S{1, 2};
    cout << s.a << s.b << endl;
    return 0;
}