#include <stdio.h>

int main(void) {
    int x;
    long long sum = 0;
    char c = 'd';

    while (c != 'n') {
        printf("Vnesi broj: ");
        scanf("%d", &x);
        sum += x;

        printf("Ushte? (d/n): ");
        scanf(" %c", &c);
    }

    printf("Sumata e %lld\n", sum);
    return 0;
}
