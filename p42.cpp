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


int pow(int y,int x)
{
    int ans=1;
    while(x--)ans=ans*y;
    return ans;
}

bool isproperty(int x)
{
    for(int i=1;i<=x;i++)
    {
        if(i*(i+1)==2*x)return true;
    }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    int sum=0;
    bool flag=false;
    int tsum=0;
    while(1)
    {

        char ch;
        int k = scanf("%c",&ch);
        if(k==EOF)break;

        switch(ch)
        {
            case ',':
                break;
            case '"':
                if(flag)
                {
                    if(isproperty(tsum))sum++;
                    tsum=0;
                    flag=false;
                }
                if(!flag)flag=true;
                break;
        }
        if(ch<='Z'&&ch>='A')tsum+=ch-'A'+1;
    }

    cout<<sum<<endl;
}
