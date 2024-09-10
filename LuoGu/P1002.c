#include <stdio.h>

int main()
{
    int n, m, n1, m1;
    scanf("%d %d %d %d", &n, &m, &n1, &m1);
    int XOY[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            XOY[i][j] = 0;
        }
    }
    XOY[n1][m1] = 1;
    XOY[n1-2][m1-1] = 1;
    XOY[n1-2][m1+1] = 1;
    XOY[n1-1][m1-2] = 1;
    XOY[n1-1][m1+2] = 1;
    XOY[n1+1][m1+2] = 1;
    XOY[n1+1][m1-2] = 1;
    XOY[n1+2][m1-1] = 1;
    XOY[n1+2][m1+1] = 1;
	for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d",XOY[i][j]);
        }
        printf("\n");
    }
    return 0;
}
    
