#include <stdio.h>

int main() {
    int proizvod;
    int kolicina;
    double vkupnoPoProizvod[6] = {0};
    double vkupnoSite = 0.0;
    double cena = 0.0;

    while (1) {
        printf("Vnesi proizvod broj (1-5, -1 za kraj): ");
        scanf("%d", &proizvod);
        if (proizvod == -1) break;

        printf("Vnesi kolicina: ");
        scanf("%d", &kolicina);

        switch (proizvod) {
            case 1: cena = 50.5; break;
            case 2: cena = 45.6; break;
            case 3: cena = 32.8; break;
            case 4: cena = 65.3; break;
            case 5: cena = 20.0; break;
            default:
                printf("Greshen proizvod broj!\n");
                continue;
        }

        vkupnoPoProizvod[proizvod] += cena * kolicina;
        vkupnoSite += cena * kolicina;
    }

    for (int i = 1; i <= 5; i++) {
        printf("Proizvod %d: %.2f\n", i, vkupnoPoProizvod[i]);
    }
    printf("Vkupno za site proizvodi: %.2f\n", vkupnoSite);

    return 0;
}
