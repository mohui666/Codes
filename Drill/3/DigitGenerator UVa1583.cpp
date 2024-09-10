#include <stdio.h>
#include <string.h>

int main()
{
    int a[100010];
    int m;
    memset(a, -1, sizeof(a)); // Initialize array with -1 to indicate no generator found

    for (m = 1; m <= 100000; m++)
    {
        int x = m, y = m;
        while (x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if (y <= 100000 && (a[y] == -1 || m < a[y]))
        {
            a[y] = m; // Store the smallest generator
        }
    }

    int n, b;
    scanf("%d", &b);
    while (b--)
    {
        scanf("%d", &n);
        if (a[n] == -1) // Check if no generator was found
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", a[n]);
        }
    }
    return 0;
}