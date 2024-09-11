#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int r=0,c=0;
    char ch;
    char a[20][20];
    int num1[20][20] ={0};
    int puzzle_number = 0;
    while(cin >> r && r)
    {
        cin >> c;
        memset(a,0,sizeof(a));
        memset(num1,0,sizeof(num1));
        int num = 1;
        if(r == 0)
        {
            break;
        }
        
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                cin >> a[i][j];
                if(i==0||j==0||a[i-1][j]=='*'||a[i][j-1]=='*')
                {
                    if(a[i][j]!='*')
                    {
                        num1[i][j]=num++;
                    }
                }
            }
        }
        
        if (puzzle_number) 
        {
            cout << endl;
        }
        cout << "puzzle #" << ++puzzle_number << ":" << endl;

        cout << "Across" << endl;
        for (int i = 0; i < r; i++) 
        {
            for (int j = 0; j < c; j++) 
            {
                if (a[i][j] != '*' && (j == 0 || a[i][j - 1] == '*')) 
                {
                    cout << "  " << num1[i][j] << ".";
                    int k = j;
                    while (k < c && a[i][k] != '*') 
                    {
                        cout << a[i][k];
                        k++;
                    }
                    cout << endl;
                }
            }
        }

        cout << "Down" << endl;
        for (int j = 0; j < c; j++) 
        {
            for (int i = 0; i < r; i++) 
            {
                if (a[i][j] != '*' && (i == 0 || a[i - 1][j] == '*')) 
                {
                    cout << "  " << num1[i][j] << ".";
                    int k = i;
                    while (k < r && a[k][j] != '*') 
                    {
                        cout << a[k][j];
                        k++;
                    }
                    cout << endl;
                }
            }
        }
        
    }
}

