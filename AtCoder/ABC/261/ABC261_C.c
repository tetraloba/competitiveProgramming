//2022-07-23 21:25:14
//2022-07-23 21:46:14 TLE
#include <stdio.h>
#include <string.h>
int count(char s[11], char S[][11], int*, int*);
int main(void){
    int N;
    char S[200000][11]; //Sはuniqueな文字列の配列
    int unique_cnt = 0, dupli_cnt[200000] = {0}; //Sの要素数, Sの要素それぞれが重複した数
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char tmps[11];
        //入力
        scanf("%s", tmps);
        //出力
        printf("%s", tmps);
        int tmp;
        if ((tmp = count(tmps, S, &unique_cnt, dupli_cnt)) != -1) {
            printf("(%d)", dupli_cnt[tmp]);
        }
        putchar('\n');
    }
    return 0;
}
int count(char s[11], char S[][11], int *n, int dupli_cnt[]){
    int flag = 1, ans;
    for (int i = 0; i < *n; i++) {
        if (!strcmp(s, S[i])){ //重複していた場合
            dupli_cnt[i]++; //該当要素の重複回数を1増やす
            ans = i; //該当要素のindexを返す(重複回数を知るため)
            flag = 0;
            break;
        }
    }
    if (flag) { //重複がなかった場合
        strcpy(S[*n], s); //Sにこの文字列を追加
        (*n)++; //Sの要素数を1増やす
        ans = -1;
    }
    return ans;
}
//いや無理でしょこれ。どう頑張ってもTLE
//unique文字列のsetを作って辞書順に並べて効率よく検索とかしないといけない感じ？
//20万個の重複しない文字列とか出されたら無理ゲーよ…
//Cめっちゃ正解者多いが？？なにか勘違いしてる…？