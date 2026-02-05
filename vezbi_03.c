#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int max=0;
    int min=-1;
    if (n>m) {
        max=n;
        min=m;

    }
    else if (m>n) {
        max=m;
        min=n;

    }
    else {
        printf("Broevite se ednakvi");
        return 0;
    }
    printf("%d e pogolem od %d", max, min);
    return 0;

}