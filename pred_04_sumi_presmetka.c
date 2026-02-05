//06

#include <stdio.h>

int main(void) {
    int x;
    long long sum = 0;

    while (1) {
        printf("Vnesi broj (-1 za kraj): ");
        scanf("%d", &x);
        if (x == -1) break;
        sum += x;
    }

    printf("Sumata e %lld\n", sum);
    return 0;
}
