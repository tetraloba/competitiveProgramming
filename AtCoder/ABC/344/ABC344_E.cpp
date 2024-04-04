// 2024/04/04 17:41:13
// 2024/04/04 20:10:09 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ELM=int;
struct Node{
    ELM value;
    Node* pre;
    Node* next;
};
Node* addNode(Node* preNode, ELM value){
    Node *newNode = new Node;
    newNode->value = value;
    newNode->pre = preNode;
    newNode->next = preNode->next;
    preNode->next = newNode;
    if (newNode->next) {
        newNode->next->pre = newNode;
    }
    return newNode;
}
void delNode(Node* tgtNode){
    if (tgtNode->next) {
        tgtNode->next->pre = tgtNode->pre;
    }
    tgtNode->pre->next = tgtNode->next;
    delete tgtNode;
}
void printNodes(Node* head){
    Node* tgt = head->next;
    while (tgt) {
        cout << tgt->value << ' ';
        tgt = tgt->next;
    }
    cout << endl;
}
// void freeNodes(Node* head){
//     while (head->next) {
//         delNode(head->next);
//     }
// }
int main(){
    int N;
    cin >> N;
    map<int, Node*> mp;
    Node head;
    head.pre = nullptr;
    head.next = nullptr;
    Node* tail = &head;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mp[a] = tail = addNode(tail, a);
    }
    // printNodes(&head); // debug
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int x, y;
            cin >> x >> y;
            mp[y] = addNode(mp[x], y);
            // printNodes(&head); // debug
        } else {
            int x;
            cin >> x;
            delNode(mp[x]);
            mp[x] = nullptr;
            // printNodes(&head); // debug
        }
    }
    printNodes(&head);
    return 0;
}
/*
毎回探索するとO(NQ)で間に合わない。
O(Q)は減らしようがないのでO(N)をどう料理するか。
ソートして二分探索は順番が変わるのでマズい。
値→indexのmapを作る？更新作業が結局重い。
クエリ毎に出力するのではなく結果のみなのでO(N+Q)に落とせるパターンか。(メタ読み)
後ろにしか挿入しないっていうのもポイントになりそう(メタ読み)

2024/04/04 19:17
map使ってQuery部分だけ先にやってしまうか。
ちょっと言葉で説明できないけど。
2024/04/04 19:22
いや同じ場所に挿入され続けるとO(Q!)になる。
削除挿入操作って基本的には連結リストだとは思うんだけど、検索が遅い(O(N))のがネック。
mapによる検索機能付き連結リストとかいうとんでもデータ構造作るか？(2024/04/04 19:23:41)
*/
