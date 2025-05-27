//2022/06/11 21:02
//2022/06/11 21:44
#include <stdio.h>
#include <math.h>
#include <float.h>
double distance(int x1, int x2, int y1, int y2);
int main(void){
    int N, K, A[1000], X[1000], Y[1000];
    int tmpI;
    double tmpD;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &tmpI);
        A[i] = tmpI - 1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    int k = 0;
    double maxMinDis = 0;
    for (int i = 0; i < N; i++) {
        if (i == A[k]) {
            k++;
        } else {
            double minDis = DBL_MAX;
            for (int j = 0; j < K; j++) {
                tmpD = distance(X[i], X[A[j]], Y[i], Y[A[j]]);
                if (tmpD < minDis) {
                    minDis = tmpD; 
                }
            }
            if (maxMinDis < minDis) {
                maxMinDis = minDis;
            }
        }
    }
    printf("%f\n", maxMinDis);
    return 0;
}
double distance(int x1, int x2, int y1, int y2){
    // printf("(%d,%d),(%d,%d):%f\n", x1, y1, x2, y2, pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5));
    return pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
}