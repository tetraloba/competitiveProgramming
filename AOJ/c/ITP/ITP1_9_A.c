#include <stdio.h>
#include <ctype.h>
int main(void){
    char str_w[11], str_text[1001], str_eot[12] = {'E','N','D','_','O','F','_','T','E','X','T'};
    int count = 0;
    scanf("%s", str_w);
    /*printf("Word is %s\n", str_w);*/    //デバッグ用
    while (1) {
        scanf(" %s", str_text);
        /*printf("text is %s\n", str_text);*/    //デバッグ用
        //END_OF_TEXTのチェック
        for (int i = 0;; i++) {
            if (str_text[i] != str_eot[i]) {
                break;
            }
            if (i == 11) {
                printf("%d\n", count);
                return 0;
            }
        }
        //Wordのチェック
        for (int i = 0;; i++) {
            if (isupper(str_text[i])) {
                str_text[i] = tolower(str_text[i]);
            }
            /*printf("str_w[%d] : %c, str_text[%d] : %c\n", i, str_w[i], i, str_text[i]);*/    //デバッグ用
            if (str_w[i] == '\0' && (str_text[i] == '\0' || str_text[i] == ',' || str_text[i] == '.' || str_text[i] == '?')) {
                count++;
                break;
            }
            if (str_text[i] != str_w[i]) {
                break;
            }
        }
        /*printf("count is %d\n", count);*/    //デバッグ用
    }
    /*END_OF_TEXT以外での異常な終了(デバッグ用)
    puts("Error");
    return 0;*/
}