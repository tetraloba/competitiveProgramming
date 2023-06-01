//2022/08/13 21:11:47
//いやいや無理無理。こんなん難しすぎるやろ。
//Aの0~(H1-H2)行それぞれについて、Bの0行目と一致する列の選び方(列index配列)を全て書き出す。
//列index配列それぞれについて、Aの、「各列index配列の0番目」の列において、Bの0列目と一致する行の選び方(行index配列)を全て書き出す。
//行index配列それぞれについて、Aから列index配列の列と行index配列の行を抜き出した行列がBと一致するか確かめる。 一致したら"Yes"->return0;
//全ての列index配列について全ての行index配列の検証をしていかなければならない。さらにそれがAの各行分(H1-H2+1回)繰り返される…
#include <iostream>
#include <vector>
using namespace std;
void func1(int A[10], int B[10], int index[p][10], int Amax, int Bmax){
    for (int i = 0; i < Bmax; i++) {
        if (A[i] == B[0]) {
            func1(&A[i + 1], &B[0 + 1], &index[0 + 1], Amax - (i + 1), Bmax - 1);
        }
    }
}
void func2();
int main(){
    int H1, W1, H2, W2, A[10][10], B[10][10];
    cin >> H1 >> W1;
    for (int i = 0; i < H1; i++) {
        for (int j = 0; j < W1; j++) {
            cin >> A[i][j];
        }
    }
    cin >> H2 >> W2;
    for (int i = 0; i < H2; i++) {
        for (int j = 0; j < W2; j++) {
            cin >> B[i][j];
        }
    }
    // B[0][0]をAから見つける
    for (int i = 0; i < H1 - H2 + 1; i++) {
        for (int j = 0; j < W1 - W2 + 1; j++) {
            if (A[i][j] == B[0][0]) {
                int p = 0;
                for (int p = 0; p < W1 - W2; p++) {
                    // B[0][]と一致するAの列を見つける
                    int indexW[p][10] = {0}; //一致する列は複数通り考えられる・・・・
                    int l = 0;
                    for (int k = 0; k < W2; k++) {
                        for (; l < W1; l++) {
                            cout << A[i][l] << ':' << B[0][k] << endl;
                            if (A[i][l] == B[0][k]) {
                                indexW[k] = l;
                                l++;
                                break;
                            }
                        }
                    }
                    //debug
                    for (int dk = 0; dk < W2; dk++) {
                        cout << indexW[dk] << ' ';
                    }
                    cout << endl;
                    if (!indexW[W2- 1]) {
                        break;
                    }
                    // B[][0]と一致するAの行を見つける
                    int indexH[10] = {0};
                    l = 0;
                    for (int k = 0; k < H2; k++) {
                        for (; l < H1; l++) {
                            if (A[l][j] == B[k][0]) {
                                indexH[k] = l;
                                l++;
                                break;
                            }
                        }
                    }
                    //debug
                    for (int dl = 0; dl < H2; dl++) {
                        cout << indexH[dl] << ' ';
                    }
                    cout << endl;
                    if (!indexH[H2 -1]) {
                        break;
                    }
                    // 一致するか確かめる
                    int flag = true;
                    for (int m = 0; m < H2; m++) {
                        for (int n = 0; n < W2; n++) {
                            cout << A[indexH[m]][indexW[n]] << ' ';
                            if (A[indexH[m]][indexW[n]] != B[m][n]) {
                                flag = false;
                            }
                        }
                        cout << endl;
                    }
                    if (flag) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                    p++;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}