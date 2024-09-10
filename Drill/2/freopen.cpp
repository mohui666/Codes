#include <stdio.h>
#include <string.h>
#define LOCAL
int main()
{
	#ifdef LOCAL
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	#endif
	int a[100];
	memset(a,0,sizeof(a));
	for(int i = 0;i<100;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 0;i<100;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

