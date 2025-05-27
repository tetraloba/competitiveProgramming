// 2024/07/11 13:45:54
// 2024/07/11 14:45:15 3WA
// 2024/07/11 14:56:22 AC.
#include <iostream>
#include <vector>
using namespace std;
using ELM=int;
struct Node{
    ELM value;
    Node *pre;
    Node *next;
};
class Dequeue{
    private:
        Node *head;
        Node *tail;
        int s;
    public:
        Dequeue();
        void push(ELM);
        void pop_front();
        void pop_back();
        ELM front(){return head->value;}
        ELM back(){return tail->value;}
        int size(){return s;}
};
Dequeue::Dequeue(){
    head = nullptr;
    tail = nullptr;
    s = 0;
}
void Dequeue::push(ELM v){
    Node *ptr = new Node;
    ptr->value = v;
    ptr->next = nullptr;
    ptr->pre = tail;
    if (s) {
        tail->next = ptr;
    } else {
        head = ptr;
    }
    tail = ptr;
    s++;
    return;
}
void Dequeue::pop_front(){
    if (!s) {
        return;
    }
    Node *del = head;
    head = head->next;
    delete del;
    s--;
}
void Dequeue::pop_back(){
    if (!s) {
        return;
    }
    Node *del = tail;
    tail = tail->pre;
    delete del;
    s--;
}

void min_push(Dequeue& dq_min, int v){
    while (dq_min.size() && v < dq_min.back()) {
        dq_min.pop_back();
    }
    dq_min.push(v);
    return;
}
void max_push(Dequeue& dq_max, int v){
    while (dq_max.size() && dq_max.back() < v) {
        dq_max.pop_back();
    }
    dq_max.push(v);
    return;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int &p : P) {
        cin >> p;
        p--;
    }

    vector<int> Pi(N);
    for (int i = 0; i < N; i++) {
        Pi[P[i]] = i;
    }

    Dequeue slide_min, slide_max;
    for (int i = 0; i < K; i++) {
        min_push(slide_min, Pi[i]);
        max_push(slide_max, Pi[i]);
    }
    int ans = slide_max.front() - slide_min.front();
    for (int i = K; i < N; i++) {
        min_push(slide_min, Pi[i]);
        max_push(slide_max, Pi[i]);
        if (Pi[i - K] == slide_min.front()) {
            slide_min.pop_front();
        }
        if (Pi[i - K] == slide_max.front()) {
            slide_max.pop_front();
        }
        ans = min(ans, slide_max.front() - slide_min.front());
    }
    cout << ans << endl;
    return 0;
}
/*
解説に有ったスライド最大値(スライド最小値)問題の解法を実装してみようと思う。
せっかくなのでDequeueも自分で作ろう。連結リストで良いよね。(2024/07/11 13:46:42)
*/
/*
両端キュー(Double Ended Queue)はDequeueではなくDequeらしい。
enqueue/dequeueと被るからか。(2024/07/11 15:00:36)
*/
