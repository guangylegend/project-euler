#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;


int p[1000005];
int biaoji[1000005];
int cnt=1;
int ks[1000005];

bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

void sha(int x)
{
    memset(biaoji,0,sizeof(biaoji));
    cnt=1;
    for(int i=2;i<=x;i++)
    {
        if(biaoji[i]==0)
        {
            p[cnt]=i;
            cnt++;
            for(int j=1;j<=x/i;j++)biaoji[j*i]=1;
        }
    }
}




int main()
{
    sha(1000000);
    int i=1;
    int j=1;
    for(int s=2;s<=1000000;s++)
    {
        int k=s;
        i=1;
        j=1;
        while(1)
        {
            if(isprime(k))break;
            if(k%p[i]==0)j++;
            while(k%p[i]==0)
            {
                k=k/p[i];
            }
            i++;
        }
        ks[s]=j;
        if(j==4&&ks[s-1]==4&&ks[s-2]==4&&ks[s-3]==4)
        {
            cout<<s-3<<endl;
            return;
        }

    }

}
