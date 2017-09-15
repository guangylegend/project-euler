#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    long long int ans=1;
    for(int i=1;i<=7830457;i++)ans=(ans*2)%10000000000;
    ans=(ans*28433+1)%10000000000;
    cout<<ans<<endl;
}
