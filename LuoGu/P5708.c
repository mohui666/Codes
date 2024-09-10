#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a<=0.0||b<=0.0||c<=0.0||a>=1000.0||b>=1000.0||c>=1000.0)
	{
		return -1;		
	}
	
	if(a+b<=c||a+c<=b||b+c<=a)
	{
		return -1;
	}
	double p = 0.5 * (a + b + c);
	double s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",s);
	return 0;
}
