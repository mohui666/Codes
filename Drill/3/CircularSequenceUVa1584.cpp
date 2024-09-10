#include <stdio.h>
#include <string.h>

int less(const char *s,int p,int q)
{
    int n = strlen(s);
    for(int i = 0;i<n;i++)
    {
        if(s[(p+i)%n]!=s[(q+i)%n])
        {
            return s[(p+i)%n] < s[(q+i)%n];
        }
        
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[1000];
    while(n--)
    {
        scanf("%s",s);
        int ans = 0;
        int m = strlen(s);
        for(int i = 0; i < m; i++)
        {
            if(less(s, i, ans))
            {
                ans = i;
            }
        }
        for(int i = 0; i < m; i++)
        {
            putchar(s[(i+ans)%m]);
        }
        putchar('\n');
    }
    return 0;
}
