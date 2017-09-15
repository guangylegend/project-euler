#include"mymath.h"
int u[12000];
int v[12000];
int c[12000];
int dist[120][120];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        memset(dist,63,sizeof(dist));

        int n,m;
        cin>>n>>m;
        for(int j=0;j<n;j++)
        {
            dist[j][j] = 0;
        }
        for(int j=0;j<m;j++)
        {
            cin>>u[j]>>v[j]>>c[j];
            dist[u[j]][v[j]] = dist[v[j]][u[j]] = min(c[j],dist[v[j]][u[j]]);
        }
        for(int l=0;l<n;l++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    dist[j][k] = min(dist[j][l]+dist[l][k],dist[j][k]);
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            if(c[j]!=dist[v[j]][u[j]])cout<<j<<endl;
        }
    }
}
