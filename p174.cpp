#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int count[250005];
long long int flag[125005];
long long int flag2[125005];

int main()
{
    int sum = 0;
    int sumk = 0;
    memset(count,0,sizeof(count));
    memset(flag,0,sizeof(flag));
    memset(flag2,0,sizeof(flag2));
    flag[0] = 0;
    flag2[0] = 0;
    for(int i=1;i<=125000;i++)
    {
        flag[i] = flag[i-1] + i;
        flag2[i] = flag[i-1]*2 + i;
    }
    for(int i=0;i<=125000;i++)
    {
        for(int j=i+1;j<=125000;j++)
        {
            if(flag[j]-flag[i]>125000)break;
            count[(flag[j]-flag[i])*2]++;
        }
        cout<<i<<endl;
    }
    for(int i=1;i<=125000;i++)
    {
        for(int j=i+1;j<=125000;j++)
        {
            if(flag2[j]-flag2[i]>250000)break;
            count[flag2[j]-flag2[i]]++;
        }
        cout<<i<<endl;
    }
    for(int i=1;i<=250000;i++)
    {
        if(count[i]==15)sumk++;
        if(count[i]<=10&&count[i]!=0)sum++;
    }
    cout<<sumk<<endl;
    cout<<sum<<endl;

}
