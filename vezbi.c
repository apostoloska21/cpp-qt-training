#include <stdio.h>

int main() {
//01

    // 02 zadaca
    int num1, num2, num3, num4;
     scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

     printf("sumata na 4te broevi: %d", num1 + num2 + num3 + num4);

    // 03 zadaca
     printf("1 2 3 4");
     printf("\n");
     printf("%d %d %d %d", 1, 2, 3, 4);
     printf("\n");
     printf("1 ");
     printf("2 ");
     printf("3 ");
     printf("4");
     printf("\n");
     //ili drug nacin:
     printf("1\n2\n3\n4\n");
//04 zadaca
    /*
 ******
*      *
*      *
*      *
*      *
*      *
*****
*/
for (int i=1; i<=6; i++) {
    for (int j=1; j<=7; j++) {
        if (i==1 || i==6 || j==1 || j==7)
            printf("*");

        else printf(" ");

        }
        printf("\n");
    }

int n=4; //pola visina
    //goren del
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-1; j++)
            printf(" ");
        if (i==1) {
            printf("***");
        }else {
            printf("*");
            for (int j=1; j<=2*i+1; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }
    //dolen del
    for (int i=n-1; i>=1; i--) {
        for (int j=1; j<=n-i; j++)
            printf(" ");
        if (i==1) {
            printf("***");
        }else {
            printf("*");
            for (int j=1; j<=2*i+1; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }
    /*   *
        ***
      *******
         *
         *
         *
         *
    */

        int i;

        printf("   *\n");
        printf("  ***\n");
        printf("*******\n");

        for (i = 0; i < 4; i++)
            printf("   *\n");

/*
                *
              *  *
            *      *
          *          *
            *      *
              *  *
                *

 */



        int x = 3;

        // goren del
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= x - i; j++)
                printf(" ");
            printf("*");
            if (i > 1) {
                for (int j = 1; j <= 2*i - 3; j++)
                    printf(" ");
                printf("*");
            }
            printf("\n");
        }

        // dolen dlel
        for (int i = x - 1; i >= 1; i--) {
            for (int j = 1; j <= x - i; j++)
                printf(" ");
            printf("*");
            if (i > 1) {
                for (int j = 1; j <= 2*i - 3; j++)
                    printf(" ");
                printf("*");
            }
            printf("\n");
        }






    return 0;
}
//
// int main() {
//     int broj;
//     scanf("%d", &broj);
//     int num1=broj/10000;
//     int num2=(broj/1000)%10;
//     int num3=(broj/100)%10;
//     int num4=(broj/10)%10;
//     int num5=broj%10;
//     printf("%d  %d  %d  %d  %d",num1, num2, num3, num4, num5);
//     return 0;
// }