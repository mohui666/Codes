#include <stdio.h>
#include <string.h>
const int maxn = 1000+10;

int main()
{
    char s[maxn];
    scanf("%s",s);
    int tot = 0;
    for(int i = 0;i<strlen(s);i++)
    {
        if(s[i]=='1')
        {
            tot++;
        }
    }
    printf("%d\n",tot);
    return 0;
}
