//2022/09/01 07:50:33
//2022/09/01 08:28:21 RE 配列外アクセスやろうな
//ABC129_D - Lamp
#include <iostream>
#include <vector>
using namespace std;
int main(){
    /* にゅーりょくなど */
    int H, W;
    cin >> H >> W;
    vector<string> S(W);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    /* 水平方向の連続数 */
    vector<vector<int>> vv1(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int cnt = 0;
            while (j + cnt < W) {
                if (S[i][j + cnt] != '.') {
                    break;
                }
                cnt++;
            }
            for (int k = 0; k < cnt; k++) {
                vv1[i][j + k] = cnt;
            }
            j += cnt;
        }
    }
    for (int i = 0; i < H; i++) { //debug
        for (int j = 0; j < W; j++) {
            cout << vv1[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl; //debug

    /* 垂直方向の連続数 */
    vector<vector<int>> vv2(H, vector<int>(W));
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            int cnt = 0;
            while (j + cnt < H) {
                if (S[j + cnt][i] != '.') {
                    break;
                }
                cnt++;
            }
            for (int k = 0; k < cnt; k++) {
                vv2[j + k][i] = cnt;
            }
            j += cnt;
        }
    }
    for (int i = 0; i < H; i++) { //debug
        for (int j = 0; j < W; j++) {
            cout << vv2[i][j] << ' ';
        }
        cout << endl;
    }

    /* 最大値探索 */
    int max = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (max < vv1[i][j] + vv2[i][j] - 1) {
                max = vv1[i][j] + vv2[i][j] - 1;
            }
        }
    }
    cout << max << endl;
    return 0;
}
//行、列それぞれで連続する最大値を求める。。
//ではいい感じに分離されたパタンで落ちるか。
// ......#
// ######.
// ######.
// ###....
// ######.
// みたいな。
//全探索は無謀やしな… え、行ける？ 2,000 * 2,000 * 2,000流石に無理か(笑)
//いい感じに全探索するしかなさそう。 2022/09/01 08:06:49
//探索を効率化するために、.の場所にindex入れていって、連続する.を数え終わったらそのindex番目に数え上げた値を入れる配列を作るっていうしょうもないこと思いついた。ポインタを使った実質変数的な扱い。
//一部RE出たけど配列外アクセス直せば時間的には間に合いそう。 2022/09/01 08:28:44
// 計算量的には2,000 * 2,000 の何倍かくらいだと思う。シランケド。
// 水平方向と垂直方向の連続数配列(vv)は別に分ける必要はないけどデバッグの観点から分けたい。