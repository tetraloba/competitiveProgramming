// 2024/04/13 21:55:21
// 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int G[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
int get_next(vector<char>& B, bool t){
    for (int g = 0; g < 8; g++) {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (t) {
                if (B[G[g][i]] == 'A') {
                    cnt++;
                }
            } else {
                if (B[G[g][i]] == 'T') {
                    cnt++;
                }
            }
        }
        if (cnt == 2) {
            for (int i = 0; i < 3; i++) {
                if (B[G[g][i]] == '.') {
                    return G[g][i];
                }
            }
        }
    }
    return -1;
}
vector<int> A(9);
int next(vector<char> B, int n){
    if (n == 9) {
        ;
    }
    int n = get_next(B, n % 2);
    if (n != -1) {
        B[n] = n % 2 ? 'T' : 'A';
    }
}
int main(){
    for (int &a : A) {
        cin >> a;
    }
    vector<char> B(9, '.');
    for (int T1 = 0; T1 < 9; T1++) {
        B[T1] = 'T';
        for (int A1 = 0; A1 < 9; A1++) {
            B[A1] = 'A';
        }
        B[T1] = '.';
    }
    cin >> ;
    cout <<  << endl;


    vector<int> seq = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    return 0;
}
/*
全探索無理なん？
9 * 8 * ... * 2 * 1 = 362880
いや最適解の行動をして云々か。。。(2024/04/13 21:57:39)
BFS,DFSかDPくらいしか道具を知らないけれど…？
基本的にこのゲームって3マス揃うことはあり得なくない？
3マス揃えさせないために相手が取るマスを誘導できるって話？

-1 1 0
-4 -2 -5
-4 -1 -5

-1 T A
-4 -2 -5
-4 -1 -5

-1 T A
-4 A -5
-4 T -5

-1 T A
-4 A -5
T T A

T T A
A A T
T T A

なんか序盤だけ決めたら勝手に決まっていきそうやな。
シミュレーションで良いのかな。

TAT
AAT
TTA

TAT
ATT
ATA

*/
