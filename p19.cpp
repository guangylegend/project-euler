#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

bool IsLeapYear(int year)
{
    if(year % 400 == 0)
    {
        return true;
    }
    else if(year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }

    return false;
}

int CountOfDays(int year, int month)
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if(IsLeapYear(year))
            {
                return 29;
            }
            return 28;
    }
    return 0;
}

int main()
{
    int initialDay = 365 % 7;
    int cnt = 0;
    int sum = 0;
    for(int year=1901; year<=2000; year++)
    {
        for(int month=1; month<=12; month++)
        {
            int days = CountOfDays(year, month);
            if((1+initialDay) % 7 == 0)
            {
                cnt++;
            }
            initialDay += days % 7;
            initialDay = initialDay % 7;
        }
    }

    cout << cnt << endl;
}
