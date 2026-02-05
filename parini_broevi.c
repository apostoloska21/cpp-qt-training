
#include <stdio.h>
#include <stdbool.h>
int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    bool n_paren = (n%2==0);
    bool m_paren = (m%2==0);

    if (n_paren && m_paren) {
        printf("broevite %d i %d se parni\n", n, m);
    }
    else if (!n_paren && !m_paren) {
        printf("broevite %d i %d  ne se parni\n", n, m);
    }
    else if (n_paren && !m_paren) {
        printf("Brojot %d e paren, a brojot %d e neparen\n", n, m);
    }
    else {
        printf("Brojot %d e paren, a brojot %d e neparen\n", m, n);
    }

    return 0;
}