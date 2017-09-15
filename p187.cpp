#include<iostream>
#include<cstring>
using namespace std;

int s[100000005];

int main()
{
    memset(s,0,sizeof(s));
    for(int i=2;i<=1e8;i++)
    {
        if(s[i]==0)
        {
            s[i]=1;
            if(i<1e4)s[i*i]=-1;
            for(int j=2;j<=1e8/i;j++)
            {
                if(j!=i&&j%i==0)s[i*j]=3;
                if(j!=i&&j%i!=0)s[i*j]++;
            }
        }
    }
    int cnt=0;
    for(int i=2;i<=1e8;i++)
    {
        if(s[i]==-1||s[i]==2)cnt++;
    }
    cout<<cnt<<endl;
}
