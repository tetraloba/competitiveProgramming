#include <iostream>
using namespace std;
void sort2(int*, int*);
int main(){
    int x, y;
    while (1) {
        cin >> x >> y;
        if (x || y) {
            sort2(&x, &y);
            cout << x << ' ' << y << '\n';
        } else {
            break;
        }
    }
    return 0;
}
void sort2(int *x, int *y){
    int tmp;
    if (*y < *x) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
    return;
}
