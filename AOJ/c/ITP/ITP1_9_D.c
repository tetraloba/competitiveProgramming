#include <stdio.h>
int main(void){
    int q, a, b;
    char str[1001], command[8];
    scanf("%s", str);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf(" %s %d %d", command, &a, &b);
        switch (command[2]) {
          case 'i' : 
            {
                for (int j = a; j <= b; j++) {
                    putchar(str[j]);
                }
                putchar('\n');
            }
            break;
          case 'v' :
            {
                char tmp = str[a];
                for (int j = 0; j < (b - a + 1) / 2; j++) {
                    tmp = str[a + j];
                    str[a + j] = str[b - j];
                    str[b - j] = tmp;
                }
            }
            break;
          case 'p' :
            {
                char p[1001];
                scanf(" %s", p);
                for (int j = 0; j < b - a + 1; j++) {
                    str[a + j] = p[j];
                }
            }
            break;
        }
    }
    return 0;
}