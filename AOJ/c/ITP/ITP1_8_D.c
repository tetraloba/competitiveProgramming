#include <stdio.h>
int main(void) {
    char str_s[101], str_p[101];
    scanf("%s", str_s);
    scanf(" %s", str_p);
    for (int i = 0; str_s[i] != '\0'; i++) {
        if (str_s[i] == str_p[0]) {
            for (int j = i, k = 0;; j++, k++) {
                if (str_s[j] == '\0') {
                    j = 0;
                }
                if (str_p[k] == '\0') {
                    puts("Yes");
                    return 0;
                } else if (str_s[j] != str_p[k]) {
                    break;
                }
            }
        }
    }
    puts("No");
    return 0;
}
