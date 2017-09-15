#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int ks[10005];

int main()
{
    int sum=0;
    for(int i=1;i<=10000;i++)
    {
        int tsum=1;
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                tsum+=j;
                if(j!=sqrt(i))tsum+=i/j;
            }
        }
        if(tsum<i&&ks[tsum]==i)sum+=(i+tsum);
        ks[i]=tsum;
    }
    cout<<sum<<endl;
}
