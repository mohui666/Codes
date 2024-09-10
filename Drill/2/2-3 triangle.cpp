#include <stdio.h>

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		for(int m = i;m>0;m--)
		{
			printf(" ");
		}
		for(int j = 2*n-2*i-1;j>0;j--)
		{
			printf("#");
		}
		printf("\n");	
		}
}
