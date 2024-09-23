#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int reverse(int num) 
{
    int rev = 0;
    while (num > 0) 
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day)
{
    if (month < 1 || month > 12) 
    {
        return false;
    }
    if (day < 1) 
    {
        return false;
    }
    if (month == 2) 
    {
        if (isLeapYear(year)) return day <= 29;
        else return day <= 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) return day <= 30;
    return day <= 31;
}

bool isPalindrome(int date) 
{
    string s = to_string(date);
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    return s == rev_s;
}
int main()
{
    int date1,date2;
    cin >> date1 >> date2;
    
    int year1 = date1 / 10000;
    int year2 = date2 / 10000;
    
    int num = 0;
    for (int i = year1; i <= year2; i++) 
    {
        int date = reverse(i);
        int month = date / 100;
        int day = date % 100;
        if (isValidDate(i, month, day)) 
        {
            int fullDate = i * 10000 + month * 100 + day;
            if (fullDate >= date1 && fullDate <= date2 && isPalindrome(fullDate)) 
            {
                num++;
            }
        }
    }
    
    cout << num << endl;
}

