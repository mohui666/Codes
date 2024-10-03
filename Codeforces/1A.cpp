#include <iostream>
using namespace std;

int main()
{
    long long n, m, a;
    cin >> n >> m >> a;

    long long num_tiles_n = (n + a - 1) / a;
    long long num_tiles_m = (m + a - 1) / a;

    cout << num_tiles_n * num_tiles_m << endl;

    return 0;
}