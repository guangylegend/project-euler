#include<iostream>
#include<cmath>
using namespace std;

long long int cnt=0;
int tot=0;
long long int xx=0;
void bfs(int n)
{
    if(n>9)
    {
        for(int i=1;i<=6;i++)
        {
            tot-=i;
            if(n==15)
            {
                if(tot>0)cnt++;
                xx++;
            }
            else bfs(n+1);
            tot+=i;
        }
    }
    else
    {
        for(int i=1;i<=4;i++)
        {
            tot+=i;
            bfs(n+1);
            tot-=i;
        }
    }
}

int main()
{
    bfs(1);
    cout<<cnt<<endl;
    cout<<xx<<endl;
    cout<<(cnt+0.0)/(pow(4,9)*pow(6,6))<<endl;
}
