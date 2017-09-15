#include<iostream>
#include<cmath>
#include<set>

using namespace std;

int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,
            71,73,79,83,89,97};
int cnt = 25;
long long int ans = 1;
long long int sum = 0;

void bfs(int n,int k)
{
    for(int i=k;i<cnt;i++)
    {
        ans*=p[i];
        if(ans<=1000000000)
        {
            sum++;
            bfs(n+1,i);
        }
        ans/=p[i];
    }
}

int main()
{
    bfs(1,0);
    cout<<sum+1<<endl;
}
