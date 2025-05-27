// 2024/04/15 18:09:46
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

}
/*
-3 1 -4 1 -5  9 -2  6 -5 3
 9 9  9 9  9  9  6  6  3 3
 6 6  6 6  6  6  3  3 -5 -
 3 3  3 3  3  3 -2 -5  - -
 1 1  1 1 -2 -2 -5  -  - -

-3 1 -4 1 -5  9 -2   6 -5   3
 9 9  9 9  9  9  6  24  3  12
 6 6  6 6  6  6  3  18 -15  -
 3 3  3 3  3  3 -2  12 -20  -
 1 1  1 1 -2 -2 -5 -15  -   -

*/