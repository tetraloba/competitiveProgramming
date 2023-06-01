#include <stdio.h>
int main(void){
    int n, t_score = 0, h_score = 0;
    char t_animal[101], h_animal[101];
    scanf("%d", &n); //回数
    for (int i = 0; i < n; i++) {
        scanf("%s %s", t_animal, h_animal);
        //字数カウント(短い方)
        int longth = 0;
        while (t_animal[longth] != '\0' && h_animal[longth] != '\0') {
            longth++;
        }
        int j = 0;
        while (j <= longth) {
            if (t_animal[j] == h_animal[j]) {
                continue;
            }
            if (t_animal[j] - h_animal[j] > 0) {
                t_score += 3;
                break;
            } else {
                h_score += 3;
                break;
            }
            j++;
        }
        if (j == longth) {
            if (t_animal[j] == h_animal[j]) {
                t_score += 1;
                h_score += 1;
            } else if (t_animal[j] == '\0') {
                h_score += 3;
            } else {
                t_score += 3;
            }
        }
    }
    printf("%d %d\n", t_score, h_score);
    return 0;
}