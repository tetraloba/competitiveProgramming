// 2025/04/01 18:44:18
// 2025/04/01 22:33:44 1WA 5RE
// 2025/04/01 22:51:41 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (b < a) {
            swap(a, b);
        }
        edges[i] = {a, b};
        G[a].push_back(i);
        if (a != b) {
            G[b].push_back(i);
        }
    }

    /* DFSで連結成分とその維持に不可欠な辺を求める */
    vector<bool> essential_edge(M); // 辺iは連結を保つために必要(付け替えない)
    vector<int> ccs(N, -1); // 頂点iを含む連結成分の番号
    vector<int> cc_root; // 連結成分iの根(=連結成分の代表頂点)
    for (int i = 0; i < N; i++) {
        if (ccs[i] != -1) {
            continue;
        }
        vector<int> stk;
        cc_root.push_back(i);
        ccs[i] = cc_root.size() - 1;
        stk.push_back(i);
        while (!stk.empty()) {
            int tgt = stk.back(); stk.pop_back();
            for (int ei : G[tgt]) {
                int arr[2] = {edges[ei].first, edges[ei].second};
                for (int next : arr) {
                    if (ccs[next] != -1) {
                        continue;
                    }
                    ccs[next] = cc_root.size() - 1;
                    essential_edge[ei] = true;
                    stk.push_back(next);
                }
            }
        }
    }
    /* debug */
    // cerr << "ccs: ";
    // for (int i : ccs) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;
    // cerr << "cc_root: ";
    // for (int i : cc_root) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    vector<vector<int>> cc_edges(cc_root.size()); // 連結成分iが持つ余剰辺のリスト
    for (int ei = 0; ei < M; ei++) {
        if (essential_edge[ei]) {
            continue;
        }
        cc_edges[ccs[edges[ei].first]].push_back(ei);
    }
    /* debug */
    // cerr << "=== cc_edges BEGIN ===" << endl;
    // for (int i = 0; i < cc_root.size(); i++) {
    //     cerr << i << ": ";
    //     for (int e : cc_edges[i]) {
    //         cerr << e << ' ';
    //     }
    //     cerr << endl;
    // }
    // cerr << "=== cc_edges END ===" << endl;

    vector<pair<int, int>> cc_edge_num(cc_edges.size()); // 余剰辺の数と連結成分番号のペア
    for (int i = 0; i < cc_edges.size(); i++) {
        cc_edge_num[i] = {cc_edges[i].size(), i};
    }
    sort(cc_edge_num.rbegin(), cc_edge_num.rend()); // 余剰辺の数が多い順にソート
    /* debug */
    // for (auto [edge_num, cc] : cc_edge_num) {
    //     cerr << '(' << edge_num << ',' << cc << ')' << ' ';
    // }
    // cerr << endl;

    vector<pair<int, pair<int, int>>> operations; // 必要な操作のリスト
    vector<pair<int, int>> stk_to_connect(cc_edge_num.rbegin(), cc_edge_num.rend()); // 連結すべき連結成分のスタック(余剰辺が少ない順に取り出す)
    for (auto [edge_num, cc] : cc_edge_num) {
        for (int ei : cc_edges[cc]) {
            if (stk_to_connect.empty()) {
                break;
            }
            auto [en, tgt] = stk_to_connect.back(); stk_to_connect.pop_back();
            if (tgt == cc) {
                if (stk_to_connect.empty()) {
                    break;
                }
                auto tmp = stk_to_connect.back(); stk_to_connect.pop_back(); // 自身は飛ばす
                tgt = tmp.second;
            }
            operations.push_back({ei, {edges[ei].second, cc_root[tgt]}});
        }
    }

    /* 回答出力 */
    cout << operations.size() << endl;
    for (auto operation : operations) {
        cout << operation.first + 1 << ' ' << operation.second.first + 1 << ' ' << operation.second.second + 1 << endl;
    }
    return 0;
}
/*
UnionFindして木になるようにBFSして余分なケーブルを繋ぎ変えたら良いんでしょう？(2025/04/01 18:46:21)
実装したいけど夕食のため中断(2025/04/01 18:46:35)
2025/04/01 19:35:13 再開
多重辺や自己ループの扱いが少し厄介か。多重辺をどうやって区別しよう(2025/04/01 19:39:24)
辺にIDつけちゃうのが早いかしら(2025/04/01 19:39:57)
2025/04/01 19:48:22 中断
2025/04/01 19:59:10 再開
2025/04/01 20:04:11 中断
2025/04/01 20:18:25 再開
2025/04/01 20:20:46 中断 買い物
2025/04/01 20:51:00 再開
どこに辺を付け替えればよいかを考えるのが意外と面倒。リングバッファ作れば良いのかしら？(2025/04/01 21:22:02)
*/
