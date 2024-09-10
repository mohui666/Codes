#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
	int a[10000],b[10000],c[10000];
	int i = 0;
	while(cin >> a[i]>> b[i] >> c[i])
	{
		
		if(a[i]==0&&b[i]==0&&c[i]==0)
		{
			break;
		}		
		else if(a[i]<=0||b[i]<=0||c[i]<=0)
		{
			return -1;
		}
		i++;
	}
	
	for(int j=0;j<i;j++)
	{
		cout << fixed << setprecision(c[j]) << a[j]*1.0/b[j]  <<endl;
	}
}
