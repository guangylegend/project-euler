#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;


bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

int main()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if((10*i*j)%(i+9*j)==0&&(10*i*j)/(i+9*j)>j)
            {
                cout<<j<<i<<' '<<i<<(10*i*j)/(i+9*j)<<endl;
            }
        }
    }
}
