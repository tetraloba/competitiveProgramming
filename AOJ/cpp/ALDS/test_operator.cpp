// #include <iostream>
// using namespace std;
// int calc(int* a, int *b){
//     return -(*a) + *(b);
// }
// int main(){
//     int a, b;
//     cin >> a >> b;
//     cout << calc(&a, &b) << endl;
//     return 0;
// }
#include <iostream>
using namespace std;
int calc(int* a){
    return *--a - *++a; // 1
    return -*a + *--a; // 2 ??
    return *a - *--a; // 3
    return *a + *--a; // 4
    return -*a-- + *a; // 5 ??
    return -*--a + *a; // 6 ??
}
int main(){
    int a[2];
    a[0] = 3;
    a[1] = 4;
    cout << calc(&a[1]) << endl;
    return 0;
}