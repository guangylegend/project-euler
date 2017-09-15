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
            for(int j=2;j<=1e8/i;j++)
            {
                int cnt=0;
                int tmp=j*i;
                while(tmp%i==0)
                {
                    cnt++;
                    tmp/=i;
                }
                if(s[j*i]==0)s[j*i]=2*cnt+1;
                else s[j*i]*=(2*cnt+1);
            }
        }
    }
    for(int i=2;i<=1e8;i++)
        if(s[i]>2001)
        {
            cout<<i<<endl;
            break;
        }
}
