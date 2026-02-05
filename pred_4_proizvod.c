#include <stdio.h>

int main(void) {
    long long product = 1;
    int x;

    for (int i = 1; i <= 10; i++) {
        printf("Vnesi broj %d: ", i);
        scanf("%d", &x);
        product *= x;
    }

    printf("Proizvodot e %lld\n", product);
    return 0;
}
