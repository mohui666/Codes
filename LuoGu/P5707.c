#include <stdio.h>

int main()
{
	int s,v,min = 8 * 60 - 10;
	scanf("%d %d",&s,&v);
	if(s % v == 0)
	{
		min -= s/v;
	}
	else
	{
		min -= (s/v)+1;
	}
	
	if(min < 0)
	{
		min += 24 * 60;
		printf("%02d:%02d",min/60,min%60);
	}
	else
	{
		printf("%02d:%02d",min/60,min%60);
	}
	
}
