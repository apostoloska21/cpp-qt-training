/* 02. i 03.  modificiranje na  p04_02_v2.c i kastiranje*/
#include <stdio.h>

int main(void) {
    int n, counter, grade, total;
    double average;

    printf("Vnesi broj na ucenici: ");
    scanf("%d", &n);

    total = 0;
    counter = 1;

    while (counter <= n) {
        printf("Vnesi ocena: ");
        scanf("%d", &grade);
        total += grade;
        counter++;
    }

    average = (double)total / n;
    printf("Srednata vrednost na klasot e %.3f\n", average);

    return 0;
}
