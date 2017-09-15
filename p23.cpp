#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int ks[30000];

bool isproperty(int k)
{
    for(int i=1;i<=k/2;i++)
    {
        if(ks[i]>i&&ks[k-i]>k-i)return true;
    }
    return false;
}

int main()
{
    int sum=0;
    for(int i=1;i<30000;i++)
    {
        int tsum=0;
        for(int j=1;j<i;j++)
        {
            if(i%j==0)tsum+=j;
        }
        ks[i]=tsum;
        if(!isproperty(i))sum+=i;
    }
    cout<<sum<<endl;
}
