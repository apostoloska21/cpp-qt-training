#include <stdio.h>

int main(void) {
    double promet;

    while (1) {
        printf("vnesi promet vo evra: "); //-1 za kraj
        scanf("%lf", &promet);

        if (promet == -1) break;

        double plata = 200.0 + 0.09 * promet;
        printf("platata e: %.2f evra\n", plata);
    }

    return 0;
}
