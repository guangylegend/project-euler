#include"mymath.h"
#include<assert.h>
#include<queue>
queue<int> q;
vector<string> v;
struct node
{
    int color;
    int next[300];
    int size;
};

int main()
{
    freopen("A-small-practice-2.in","r",stdin);
    freopen("A-small-practice-2.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        v.clear();
        int m;
        cin>>m;
        node s[300];
        for(int j=1;j<=m;j++)
        {
            string a,b;
            int aa=-1,bb=-1;
            cin>>a>>b;
            std::vector<string>::iterator it;
            it = find(v.begin(), v.end(), a);
            if(it != v.end())aa = it-v.begin();
            else
            {
                v.push_back(a);
                s[v.size()-1].color = -1;
                s[v.size()-1].size = 0;
                aa = v.size()-1;
            }
            it = find(v.begin(), v.end(), b);
            if(it != v.end())bb = it-v.begin();
            else
            {
                v.push_back(b);
                s[v.size()-1].color = -1;
                s[v.size()-1].size = 0;
                bb = v.size()-1;
            }
            s[aa].next[s[aa].size] = bb;
            s[aa].size++;
            s[bb].next[s[bb].size] = aa;
            s[bb].size++;
        }
        bool flag = false;
        while(1)
        {
            if(q.size()==0)
            {
                bool fg = false;
                for(int j=0;j<v.size();j++)
                {
                    if(s[j].color==-1)
                    {
                        s[j].color = 1;
                        q.push(j);
                        fg = true;
                        break;
                    }
                }
                if(!fg)break;
            }
            else
            {
                int tmp = q.front();
                for(int j=0;j<s[tmp].size;j++)
                {
                    if(s[s[tmp].next[j]].color==s[tmp].color)
                    {
                        flag=true;
                        break;
                    }
                    if(s[s[tmp].next[j]].color==-1)q.push(s[tmp].next[j]);
                    s[s[tmp].next[j]].color=1-s[tmp].color;
                }
                q.pop();
            }
        }
        if(flag == false) cout<<"Case #"<<i<<": Yes"<<endl;
        else cout<<"Case #"<<i<<": No"<<endl;
    }
}
