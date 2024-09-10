#include <stdio.h> 
#include <math.h>
int main()
{
	int i = 100;
	for(;i<1000;i++)
	{
		if(i==pow(i%10,3)+pow(i/10%10,3)+pow(i/100%10,3))
		{
			printf("%d\n",i);
		}
	}
}
