#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long ll;
list<ll> lt[N];

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        if(s=="push_back")
        {
			int a ;
            ll x;
            cin>>a>>x;
			lt[a].push_back(x);
		}
        else if(s=="pop_back")
        {
			int a;cin>>a;
			if(lt[a].empty())
            {
                continue;
            }
			else
            { 
                lt[a].pop_back();
            }
        }
        else if(s=="push_front")
        {
			int a;
            ll x;
            cin>>a>>x;
			lt[a].push_front(x);
		}
        else if(s=="pop_front")
        {
			int a;cin>>a;
			if(lt[a].empty())
            {
                continue;
            }
            else
            {
                lt[a].pop_front();
            }
		}
        else if(s=="size")
        {
			int a;
            cin>>a;
			cout<<lt[a].size()<<'\n';
		}
        else if(s=="front")
        {
			int a;
            cin>>a;
			if(lt[a].empty())
            {
                continue;
            }
            else
            {
                cout<<lt[a].front()<<'\n';
            }
        }
        else if(s=="back")
        {
			int a;
            cin>>a;
			if(lt[a].empty())
            {
                continue;
            }
            else
            {
                cout<<lt[a].back()<<'\n';
            }
		}

    }
}