#include <iostream>
long long int factorial(long long int N){
    if (N < 2) {
        return 1;
    }
    return N * factorial(N - 1);
}
int main(){
    // std::cout << factorial(40) << std::endl;
    long long int sum = 1;
    for (int i = 1; i <= 30; i++) {
        sum *= i;
        std::cout << i << ' ' << sum << std::endl;
    }
    return 0;
}