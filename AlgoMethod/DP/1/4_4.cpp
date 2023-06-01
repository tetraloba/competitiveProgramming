#include <iostream>
int func123(int N){
    if (!N) return 1;
    int sum = 0;
    if (1 <= N) sum += func123(N - 1);
    if (2 <= N) sum += func123(N - 2);
    if (3 <= N) sum += func123(N - 3);
    return sum;
}
int main(){
    int N;
    std::cin >> N;
    std::cout << func123(N) << std::endl;
    return 0;
}