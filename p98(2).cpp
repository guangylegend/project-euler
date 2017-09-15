#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
int aa[30];
int bb[30];
vector<char> a[10000];

void test(int i,int j)
{
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));
    if(a[i].size()!=a[j].size())return;
    for(int k=0;k<a[i].size();k++)
    {
        if(aa[a[i][k]-65]==0)aa[a[i][k]-65]=1;
        else return;
    }
    for(int k=0;k<a[j].size();k++)
    {
        if(bb[a[j][k]-65]==0)bb[a[j][k]-65]=1;
        else return;
    }
    for(int k=0;k<30;k++)
    {
        if(aa[k]!=bb[k])return;
    }
    for(int k=0;k<a[i].size();k++)cout<<a[i][k];
    cout<<' ';
    for(int k=0;k<a[j].size();k++)cout<<a[j][k];
    cout<<endl;
}

int main()
{
    freopen("words.txt","r",stdin);
    int cnt=0;
    int strcnt=0;
    char ch;
    while(scanf(" %c",&ch)==1)
    {
        if(ch=='"')cnt==0;
        else if(ch==',')
        {
            strcnt++;
        }
        else
        {
            a[strcnt].push_back(ch);
            cnt++;
        }
    }
    for(int i=0;i<strcnt-1;i++)
    {
        for(int j=i+1;j<strcnt-1;j++)
        {
            test(i,j);
        }
    }
}
