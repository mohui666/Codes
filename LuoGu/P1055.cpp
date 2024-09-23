#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int end = (s[0] - '0') * 1 + (s[2] - '0') * 2 + (s[3] - '0') * 3 + (s[4] - '0') * 4 + (s[6] - '0') * 5 + (s[7] - '0') * 6 + (s[8] - '0') * 7 + (s[9] - '0') * 8 + (s[10] - '0') * 9;
    end %= 11;
    char checkChar = (end == 10) ? 'X' : (end + '0');
    if (checkChar == s[12])
    {
        cout << "Right";
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            cout << s[i];
        }
        cout << checkChar;
    }
}