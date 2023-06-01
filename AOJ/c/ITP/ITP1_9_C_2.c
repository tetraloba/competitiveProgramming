#include <stdio.h>
int main(void){
    int n, t_score = 0, h_score = 0;
    char t_animal[101], h_animal[101];
    scanf("%d", &n); //回数
    for (int i = 0; i < n; i++) {
        scanf("%s %s", t_animal, h_animal);
        int j = 0;
        while (1) {
            if (t_animal[j] == '\0' && h_animal[j] == '\0') {
                t_score += 1;
                h_score += 1;
                break;
            }else if (0 < t_animal[j] - h_animal[j] || h_animal[j] == '\0') {
                t_score += 3;
                break;
            } else if (t_animal[j] - h_animal[j] < 0 || t_animal[j] == '\0') {
                h_score += 3;
                break;
            } 
            j++;
        }
    }
    printf("%d %d\n", t_score, h_score);
    return 0;
}