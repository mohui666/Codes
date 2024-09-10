#include <stdio.h>

int main()
{
	int h,r;
	scanf("%d %d",&h,&r);
	int m;
	if(20000/(h*3.14*r*r)==0)
	{
		m = 20000/(h*3.14*r*r);
	}
	else
	{
		m = 20000/(h*3.14*r*r) + 1;
	}
	printf("%d",m);
}
