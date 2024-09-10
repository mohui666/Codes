#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a<0||b<0)
	{
		return 1;
	}
	printf("%d",a * b);
	return 0;
}
