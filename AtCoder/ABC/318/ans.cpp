/* 公式解説から作成 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> weight(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
            cin >> weight[i][j];
        }
    }

	vector<long long> dp(1 << N);
    for (int b = 0; b < dp.size(); b++) {
        // cerr << b << endl;
		int l = -1;
        for (int i = 0; i < N; i++) {
            if (!(b >> i & 1)) {
                l = i;
                break;
            }
        }
        for (int i = 0; i < N; i++) {
            if (!(b >> i & 1)) {
                int newb = b | (1 << l) | (1 << i);
                dp[newb] = max(dp[newb], dp[b] + weight[l][i]);
                // cerr << '\t' << l << ',' << i << endl;
            }
        }
	}
	cout << dp.back() << endl;
}
/*
0000:
    1100
    1010
    1001
0001:
    1101
    1011
0010:
    1110
    1011
0011:
    1111 # ここでは0011が0のままなのでwrong

0100:
    1110
    1101
0101:
    1111
0110:
    1111
0111:

1000:
    1110
    1101
1001:
    1111
1010:
    1111
1011:
1100:
    1111 # ここで初めて1100と0011の組の正しい値が評価される
1101:
1110:
1111:

*/
