#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[85];
        scanf("%s", s);
        int len = strlen(s);
        int period = len;

        for (int k = 1; k <= len / 2; k++)
        {
            if (len % k == 0)
            {
                int is_periodic = 1;
                for (int i = k; i < len; i++)
                {
                    if (s[i] != s[i % k])
                    {
                        is_periodic = 0;
                        break;
                    }
                }
                if (is_periodic)
                {
                    period = k;
                    break;
                }
            }
        }
        printf("%d\n", period);
        if (t) printf("\n");
    }
    return 0;
}