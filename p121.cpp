#include<iostream>
#include<cstring>
#include<cmath>
#include<set>

using namespace std;
long long int ans = 1;
long long int sum = 0;
bool a[16];

void bfs(int k,int n,int last)
{
    for(int i=last+1;i<=15;i++)
    {
        if(!a[i])
        {
            ans*=i;
            a[i] = true;
            if(k==n)sum+=ans;
            else bfs(k+1,n,i);
            ans/=i;
            a[i] = false;

        }
    }
}

int main()
{
    long long int l = 0;
    for(int i=1;i<=7;i++)
    {
        ans = 1;
        sum = 0;
        for(int j=1;j<=15;j++)a[j] = false;
        bfs(1,i,0);
        l += sum;
        cout<<l<<endl;
    }
    cout<<l+1<<endl;
}
