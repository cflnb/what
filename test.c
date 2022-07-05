#include<stdio.h>

int main() {
    char c;
    int n, m;
    scanf("%c%d%d", & c, & n, & m);
    for (int i = 0; i <= n+1; i++) {
        n--;
        for (int j = 1; j <= n; j++)
            printf("  ");
        for (int j = 1; j <= m; j++)
            printf("%c ", c);
        printf("\n");
    }
    return 0;
}
