#include <stdio.h>
#define PI 3.1415
int main() {
    float r;

    scanf("%f", &r);

    float plostina = PI * r * r;
    float perimetar = 2 * PI * r;

    printf("Plostina: %.2f\n", plostina);
    printf("Perimetar: %.2f\n", perimetar);

    return 0;
}
