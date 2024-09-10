#include <stdio.h>
#include <string.h>
int main()
{
	int n[10],m;
	memset(n,0,sizeof(n));
	for(int i = 123;i<333;i++)
	{
		n[i/100] = n[i/10%10] = n[i%10] = 1;
		n[2*i/100] = n[2*i/10%10] = n[2*i%10] = 1;
		n[3*i/100] = n[3*i/10%10] = n[3*i%10] = 1;
		if(n[0]==1)
		{
			
		}
		for(int a = 1;a<10;a++)
		{			
			m += n[a];
		}
		if(m == 9)
		{
			printf("%d %d %d\n",i,2*i,3*i);
		}
		memset(n,0,sizeof(n));
		m=0;
	}
	return 0;
}

