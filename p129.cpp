#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int check(int n)
{
    int cnt = 1;
    int rem = 1;
    int ans = 0;
    while(1)
    {
        ans=(ans+rem)%n;
        if(ans!=0)
        {
            cnt++;
            rem = rem*10%n;
        }
        else return cnt;
    }
}

int main()
{
    int i = 1;
    while(1)
    {
        i++;
        if(i%10000==0)cout<<i<<endl;
        if(i%2==0||i%5==0)continue;
        if(check(i)>1000000)
        {
            cout<<i<<endl;
            break;
        }
    }

}
