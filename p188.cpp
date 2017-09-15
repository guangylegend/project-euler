#include<iostream>
#include<cstring>

using namespace std;

int rem[100000005];

int main()
{
    int a = 1777;
    int b = 1855;
    memset(rem,0,sizeof(rem));
    rem[0]=1;
    for(int i=1;i<100000000;i++)rem[i]=((long long int)rem[i-1]*a)%100000000;
    long long int ans = a;
    for(int i=1;i<b;i++)ans = rem[ans];
    cout<<ans<<endl;
}
