//2022/05/29 22:02
//2022/05/29 22:11 AC
#include <stdio.h>
int main(void){
    char str[101];
    scanf("%s", str);
    int low = 0, up = 0, dif = 1;
    for (int i = 0; str[i]; i++) {
        if (!up && 0 <= str[i] - 'A' && str[i] - 'Z' <= 0) {
            up = 1;
        } else if (!low && 0 <= str[i] - 'a' && str[i] - 'z' <= 0) {
            low = 1;
        }
        for (int j = 0; j < i; j++) {
            if (str[j] == str[i]) {
                dif = 0;
            }
        }
    }
    if (low && up && dif) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}