#include <stdio.h>
#include <string.h>

int main()
{
    int a[10];
    memset(a, 0, sizeof(a));
    int i,m;
    scanf("%d", &m);   
    while(m--)
    {
        memset(a, 0, sizeof(a));
        scanf("%d", &i);
        for (int j = 1; j <= i; j++)
        {
            int m = j;
            while (m != 0)
            {
                a[m % 10]++;
                m = m / 10;
            }
        }
        for (int j = 0; j < 10; j++)
        {
            if(j>0)
            {
                printf(" ");
            }
            printf("%d", a[j]);
        }
        printf("\n");        
    }
    return 0;
}