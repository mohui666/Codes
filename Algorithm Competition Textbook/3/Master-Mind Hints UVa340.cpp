#include <stdio.h>
const int maxn = 1010;

int main()
{
    int n, a[maxn], b[maxn];
    int kase = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        printf("Game %d:\n", ++kase);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        while(1)
        {
            int A = 0, B = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &b[i]);
                if (a[i] == b[i])
                {
                    A++;
                }
            }
            if (b[0] == 0)
            {
                break;
            }
            for (int j = 1; j <= 9; j++)
            {
                int c1 = 0, c2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] == j)
                    {
                        c1++;
                    }
                    if (b[i] == j)
                    {
                        c2++;
                    }
                }
                B += c1 > c2 ? c2 : c1;
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int _max = 1e3+50;
// int a[_max],b[_max],n,k=1;
// int main()
// {
// 	while(cin>>n&&n)
// 	{
// 		printf("Game %d:\n",k++);
// 		for(int i=0;i<n;i++)
// 		  cin>>a[i];
// 		while(true)
// 		{
// 			int ans1=0,ans2=0;
// 			for(int i=0;i<n;i++)
// 			{
// 				cin>>b[i];
// 				if(a[i]==b[i])//先统计正确的个数
// 				  ans1++;
// 			}
// 			if(b[0]==0) break;//退出条件
// 			for(int i=1;i<=9;i++)
// 		    {
// 				int b1=0,b2=0;
// 				for(int j=0;j<n;j++)
// 				{
// 					if(a[j]==i)
// 					  b1++;//a数组中出现次数
// 					if(b[j]==i)
// 					  b2++;//b数组中出现次数
// 				}
// 				ans2+=min(b1,b2);//每次取最小值
// 			}
// 			printf("    (%d,%d)\n",ans1,ans2-ans1);
// 		}
// 	}
// 	return 0;
// }