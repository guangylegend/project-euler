#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>

using namespace std;

int a[15];
long long int sums = 0;
int flag =1;

int p[100000];

int convert()
{
    int ans = 0;
    for(int i=0;i<10;i++)
    {
        ans+=a[i]*pow(3,i);
    }
    return ans;
}

long long int jie(int n)
{
    if(n==1)return 1;
    else return n*jie(n-1);
}

long long int calc(int twice)
{
    return jie(10)/pow(2,twice);
}

void dfs(int n,int sum,int s)
{
    if(n==11)
    {
        if(sum==s)
        {
            if(p[convert()]!=0)return;
            else p[convert()]=1;
            int twice = 0;
            for(int i=0;i<10;i++)
            {
                if(a[i]==1)cout<<i<<' ';
                else if(a[i]==2)
                {
                    cout<<i<<' '<<i<<' ';
                    twice++;
                }
            }
            cout<<endl;
            if(sum!=45)sums+=2*calc(twice)*calc(twice);
            else sums+=calc(twice)*calc(twice);
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(n==1 && (i+2)*10>sum)return;
            if(a[i]<2)
            {
                if(s+i>sum)return;
                a[i]++;
                s+=i;
                dfs(n+1,sum,s);
                s-=i;
                a[i]--;
            }
        }
    }
}

int main()
{
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    dfs(1,23,0);
    dfs(1,34,0);
    dfs(1,45,0);
    //cout<<9*(10*jie(10)*jie(10)/pow(2,10)+jie(20)/(11*pow(2,10)))/10;
    cout<<9*sums/10<<endl;

}
