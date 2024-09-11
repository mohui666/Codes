#include <stdio.h>
#include <ctype.h>

#define C 12.01
#define H 1.008
#define N 14.01
#define O 16.00
double MassPlus(const char a,int b);

int main()
{
    char s[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double Mass=0.0;
        scanf("%s",s);
        for (int i = 0; s[i] != '\0'; i++)
        {
            if(isalpha(s[i]))
            {
                
                if (isdigit(s[i+1]))
                {
                    if (isdigit(s[i+2]))
                    {
                        Mass += MassPlus(s[i], (int)(s[i+1] - '0') * 10 + (int)(s[i+2] - '0'));
                        i += 2;
                    }
                    else
                    {
                        Mass += MassPlus(s[i], s[i+1] - '0');
                        i += 1;
                    }
                }
                else
                {
                    Mass += MassPlus(s[i],1);
                }    
            }
            
        }
        printf("%0.3lf\n",Mass);
    }
}

double MassPlus(const char a,int b)
{
    switch (a) {
        case 'C':
            return C * b;
        case 'H':
            return H * b;
        case 'N':
            return N * b;
        case 'O':
            return O * b;
        default:
            return 0.0;
    }    
}