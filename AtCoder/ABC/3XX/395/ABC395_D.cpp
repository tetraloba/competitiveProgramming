// 2025/03/03 14:11:24
// 2025/03/03 14:24:17 AC.
#include <iostream>
#include <vector>
using namespace std;
struct Nest{
    int no;
};
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<Nest> nests(N);
    vector<Nest*> bird_nest_ptrs(N), nest_nest_ptrs(N);
    for (int i = 0; i < N; i++) {
        nests[i].no = i;
        bird_nest_ptrs[i] = &nests[i];
        nest_nest_ptrs[i] = &nests[i];
    }

    for (int q = 0; q < Q; q++) {
        int op, a, b;
        cin >> op;
        switch (op) {
            case 1:
                cin >> a >> b;
                a--; b--;
                bird_nest_ptrs[a] = nest_nest_ptrs[b];
                break;
            case 2:
                cin >> a >> b;
                a--; b--;
                swap(nest_nest_ptrs[a], nest_nest_ptrs[b]);
                nest_nest_ptrs[a]->no = a;
                nest_nest_ptrs[b]->no = b;
                break;
            case 3:
                cin >> a;
                a--;
                cout << bird_nest_ptrs[a]->no + 1 << endl;
                break;
        }
    }
    return 0;
}
