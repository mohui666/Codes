#include <stdio.h>

long fac(long a);

int main()
{
    long a;
    scanf("%ld", &a);
    if(a < 0)
    {
    	return -1;
	}
    printf("%ld", fac(a));
    return 0;
}

long fac(long a)
{
    if (a == 0 || a == 1)
    {
        return 1;
    }
    return a * fac(a - 1);
}
