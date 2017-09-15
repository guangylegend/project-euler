#include"mymath.h"
int direct[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int lpos=1,rpos=1;
        int ndir = 0;
        int length = 1;
        int r,c,x;
        cin>>x>>r>>c;
        map<int,char> m;
        map<pair<int,int>,int> last;
        for(int j=1;j<=x;j++)
        {
            int sec;
            char dir;
            cin>>sec>>dir;
            //cout<<sec<<' '<<dir<<endl;
            m.insert(make_pair(sec,dir));
        }
        last.insert(make_pair(make_pair(1,1),0));
        for(int j=1;j<=2000000;j++)
        {
            lpos+=direct[ndir][0];
            if(lpos==0)lpos=r;
            if(lpos==r+1)lpos=1;
            rpos+=direct[ndir][1];
            if(rpos==0)rpos=c;
            if(rpos==c+1)rpos=1;
            if(last.count(make_pair(lpos,rpos)))
            {
                if(last[make_pair(lpos,rpos)]+length>j)break;
            }
            else
            {
                if((lpos+rpos)%2==1)length++;
            }
            last[make_pair(lpos,rpos)] = j;
            if(m.count(j))
            {
                if(m[j]=='R')ndir++;
                else ndir--;
                ndir&=3;
            }
            //cout<<ndir<<' '<<lpos<<' '<<rpos<<endl;
        }
        cout<<"Case #"<<i<<": "<<length<<endl;
    }
}
