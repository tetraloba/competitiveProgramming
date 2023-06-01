#include <stdio.h>
#include <ctype.h>
int main(void){
    int ch, arr[26] = {0};
    while ((ch = getchar()) != EOF) {
        if (isupper(ch)) {
            ch = tolower(ch);
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (ch == i) {
                arr[i - 'a']++;
            }
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        printf("%c : %d\n", i, arr[i - 'a']);
    }
    return 0;
}