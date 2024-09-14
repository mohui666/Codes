#include <iostream>
using namespace std;

int main()
{
    int week[8][2]={0};
    int sum[8];
    for(int i=1;i<=7;i++)
    {
        cin >> week[i][0] >> week[i][1];
        sum[i] = week[i][0] + week[i][1];
    }

    int max = 0;
    int maxDay = 0;
    for(int i = 1;i<=7;i++)
    {
        if(sum[i]>8)
        {
            if(sum[i]>max)
            {
                max = sum[i];
                maxDay = i;
            }
        }
    }

    cout << maxDay;
}

    