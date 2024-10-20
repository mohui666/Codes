#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s,a,b;
    cin >> s >> a >> b;
    double x=(a+b)*s/(b+3*a);
    printf("%0.6f",x/b+(s-x)/a);
}