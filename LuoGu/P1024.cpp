#include <bits/stdc++.h>
using namespace std;

double a,b,c,d;

double f(double x)
{
    return a*pow(x,3) + b*pow(x,2) + c*x + d;
}

int main()
{
    cin >> a >> b >> c >> d;
    vector<double> res;

    for(double i = -100;i<=100;i++)
    {
        double j = i + 1;
        if(f(i)==0)
        {
            res.push_back(i);
            continue;
        }
        else if(f(i)*f(j)<0)
        {
            double l = i,r = j;
            double mid = (l+r)/2;
            for(int k = 0;k<=100;k++)
            {
                mid = (l+r)/2;
                if(f(mid)==0)
                {
                    break;
                }
                else if(f(mid)*f(l)<0)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            res.push_back(mid);  
        }
    }

    for(auto i : res)
    {
        printf("%0.2f ",i);
    }
}