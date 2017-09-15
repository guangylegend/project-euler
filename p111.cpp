#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

long long int ans[10];
int length[10];
long long int a = 0;

bool isprime(long long int n)
{
    bool flag = true;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool check(long long int n)
{
    int digit[10];
    memset(digit,0,sizeof(digit));
    while(n>0)
    {
        digit[n%10]++;
        n/=10;
    }
    for(int i=0;i<10;i++)
    {
        if(digit[i]>=1 && digit[i]>=length[i])return true;
    }
    return false;
}

int main()
{
    memset(ans,0,sizeof(ans));
    memset(length,0,sizeof(length));
    for(long long int i=1000000000;i<10000000000;i++)
    {
        if((i-1000000000)%900000000==0)cout<<(i-1000000000)/90000000<<'%'<<endl;
        if(check(i) && isprime(i))
        {
            int digit[10];
            memset(digit,0,sizeof(digit));
            long long int n = i;
            while(n>0)
            {
                digit[n%10]++;
                n/=10;
            }
            for(int k=0;k<10;k++)
            {
                if(digit[k]>length[k])
                {
                    length[k] = digit[k];
                    ans[k] = i;
                }
                else if(digit[k]==length[k])ans[k]+=i;
            }
        }
    }
    for(int i=0;i<10;i++)a+=ans[i];
    cout<<a<<endl;
}
