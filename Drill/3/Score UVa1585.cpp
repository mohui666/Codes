#include <stdio.h>
#include <string.h>
int main()
{
    char s[90];  
    int j=0;
    scanf("%d",&j);
    while(j--)
    {
        int l = 0,sum=0;
        scanf("%s",s);
        for(int i = 0;i<strlen(s);i++)
        {
            if(s[i]=='X')
            {
                l=0;
            }
            else if(s[i]=='O')
            {
                l++;
            }
            sum+=l;
        }
    printf("%d\n",sum);
    }
    return 0;
}