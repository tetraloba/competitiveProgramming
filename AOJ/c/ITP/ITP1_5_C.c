#include <stdio.h>
int main(void){
    int Hight, Width;

    while (1) {
        scanf("%d %d", &Hight, &Width);
        if (Hight * Width == 0) {
            break;
        }

        for (int i = 0; i < Hight; i++) {
            for (int j = 0; j < Width; j++) {
                if ((i + j) % 2 == 0) {
                    putchar('#');
                } else {
                    putchar('.');
                }
            }
            putchar('\n');
        }
        putchar('\n');
    }
    
    return 0;
}