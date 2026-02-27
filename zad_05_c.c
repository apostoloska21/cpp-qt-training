#include <stdio.h>

int main(void) {
    int a, b, c;

    for (a = 1; a <= 100; a++) {
        for (b = a; b <= 100; b++) {          /* b od a za da nemat duplikati */
            for (c = b; c <= 100; c++) {      /* c >= b */
                if (a*a + b*b == c*c) {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
