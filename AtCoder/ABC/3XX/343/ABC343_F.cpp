// 2024/04/04 20:47:52
// 
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ELM=int;
class Heap{
    private:
        vector<ELM> v;
        map<ELM, int> mp; // for find()
        int parent(int i){return (i - 1) / 2;}
        int child(int i, bool right){return i * 2 + 1 + right;}
        int up(int i);
        int down(int i);
    public:
        int push(ELM value);
        void del(int i);
        ELM top(){return v[0];}
        ELM sec();
        int find(ELM value); // valueを持つ要素のindexを返す
};
int Heap::up(int i){
    while (i) {
        int parent_i = parent(i);
        if (v[i] < v[parent_i]) {
            break;
        }
        swap(v[parent_i], v[i]);
        mp[v[parent_i]] = i;
        mp[v[i]] = parent_i;
        i = parent_i;
    }
    return i;
}
int Heap::down(int i){
    while (i < v.size()) {
        int child_i = child(i, false);
        if (v[i] < v[child_i]) {
            swap(v[i], v[child_i]);
            mp[v[child_i]] = i;
            mp[v[i]] = child_i;
            i = child(i, false);
            continue;
        }
        child_i = child(i, true);
        if (v[i] < v[child_i]) {
            swap(v[i], v[child_i]);
            mp[v[child_i]] = i;
            mp[v[i]] = child_i;
            i = child_i;
            continue;
        }
        break;
    }
    return i;
}
int Heap::push(ELM value){
    v.push_back(value);
    mp[value] = v.size();
    return up(v.size());
}
void Heap::del(int i){
    swap(v[i], v.back());
    mp[v[i]] = i;
    mp[v.back()] = -1;
    v.pop_back();
    up(i);
    down(i);
}
ELM Heap::sec(){
    if (v.size() < 2) {
        return -1;
    }
    if (v.size() == 2) {
        return v[1];
    }
    return v[1] < v[2] ? v[2] : v[1];
}
int Heap::find(ELM value){
    ;
}
int main(){
    int N, Q;
    cin >> N >> Q;
    map<ELM, int> cnt;
    Heap heap;
    int heap_size = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (!cnt[a]) {
            heap.push(a);
        }
        cnt[a]++;
    }
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int p, x;
            cin >> p >> x;
        } else {
            int l, r;
            cin >> l >> r;
        }
    }
    cout <<  << endl;
    return 0;
}
/*
どうせ解けないだろうと思って軽い気持ちで開いたらなんだか解けそうな気がした。
Second Largestはheap書けば求められるでしょう？
数はmapで管理すればよくない？
heapは更新可能にする必要はあるかな。ちょっと実装してみるか。(2024/04/04 20:49:19)
駄目だ。heapのtopをpopした時の実装を忘れた。講義資料見直してくる。(2024/04/04 21:06:42)
あ、l~rの範囲指定有るのか。無理だな。セグ木でしょこれ。(2024/04/04 22:16:35)
*/
