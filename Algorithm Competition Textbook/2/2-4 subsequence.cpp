#include <stdio.h>

int main()
{
	int m[10000],n[10000],i;
	double sum=0;
	
	for(i = 0;scanf("%d %d",&n[i],&m[i])==2;i++)
	{
		
		if(!n[i]&&!m[i])
		{
			break;
		}
		else if(n[i]>=m[i])
		{
			return -1;
		}
		
	}
	
	for(int j = 0;j<i;j++)
	{
		for(;n[j]<=m[j];n[j]++)
		{
			sum += 1/(n[j]*1.0*n[j]*1.0);
		}
	}
    printf("%0.5lf",sum);
}
