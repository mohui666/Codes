#include <stdio.h>

int main()
{
	void sort(int array[],int n);
	int a[10],i;
	for(i;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,10);
	for(int i = 0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
}

void sort(int array[],int n)
{
	int a,b,c,d;
	for(a = 0;a<n-1;a++)
	{
		for(b = a + 1;b<n;b++)
		{
			if(array[a]>array[b])
			{
				c = array[b];
				array[b] = array[a];
				array[a] = c;
			}
		}
	}
}


