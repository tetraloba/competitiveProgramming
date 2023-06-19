// テストケース作成プログラム

//  [新潟大2019編入(2)]
// 1~99までの整数のうち4つの数（重複可）を入力し、入力された数をつなぎ合わせて最大となる数を出力するC言語プログラムを作成せよ。
// 例えば、4、6、77、9を入力した場合、97764が答えとなる。
// 使用した変数やプログラムの動作に関する部分には可能な限りコメントをつけること。

#include <stdio.h>
#include <stdlib.h>
#define NUM 4
#define NUM_CASE 1000 // 作成するケースの数
int main(void){
    for (int i = 0; i < NUM_CASE; i++) {
        for (int j = 0; j < NUM; j++) {
            printf("%d ", rand() % 99 + 1);
        }
        putchar('\n');
    }
    return 0;
}
