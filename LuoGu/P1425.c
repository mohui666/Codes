#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int m,h;
	if(d - b < 0)
	{
		m = d - b + 60;
		h = c - a - 1;
	}
	else
	{
		m = d - b;
		h = c - a;
	}
	printf("%d %d",h,m);
}
