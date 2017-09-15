#include"mymath.h"

int s[25][25];

int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        string dir;
        cin>>dir;
        for(int j=0;j<=23;j++)
            for(int k=0;k<=23;k++)
                s[j][k] = 0;
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                cin>>s[j][k];
        if(dir=="left")
        {
            for(int j=1;j<=n;j++)
            {
                int cnt = 1;
                for(int k=1;k<=n;k++)
                {
                    if(cnt>n)
                    {
                        s[j][k] = 0;
                    }
                    else
                    {
                        if(s[j][cnt]==0)
                        {
                            bool flag = false;
                            for(int kk=cnt;kk<=n;kk++)
                            {
                                if(s[j][kk]!=0)
                                {
                                    cnt = kk;
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag)cnt = n+1;
                        }

                        int cntpp = n+1;
                        for(int kk=cnt+1;kk<=n;kk++)
                        {
                            if(s[j][kk]!=0)
                            {
                                cntpp = kk;
                                break;
                            }
                        }
                        if(s[j][cnt]==s[j][cntpp])
                        {
                            s[j][k] = s[j][cnt]*2;
                            cnt = cntpp + 1;
                        }
                        else
                        {
                            s[j][k] = s[j][cnt];
                            cnt = cntpp;
                        }
                    }
                }
            }
        }
        else if(dir=="right")
        {
            for(int j=1;j<=n;j++)
            {
                int cnt = n;
                for(int k=n;k>=1;k--)
                {
                    if(cnt<1)
                    {
                        s[j][k] = 0;
                    }
                    else
                    {
                        if(s[j][cnt]==0)
                        {
                            bool flag = false;
                            for(int kk=cnt;kk>=1;kk--)
                            {
                                if(s[j][kk]!=0)
                                {
                                    cnt = kk;
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag)cnt = 0;
                        }

                        int cntpp = 0;
                        for(int kk=cnt-1;kk>=1;kk--)
                        {
                            if(s[j][kk]!=0)
                            {
                                cntpp = kk;
                                break;
                            }
                        }
                        if(s[j][cnt]==s[j][cntpp])
                        {
                            s[j][k] = s[j][cnt]*2;
                            cnt = cntpp - 1;
                        }
                        else
                        {
                            s[j][k] = s[j][cnt];
                            cnt = cntpp;
                        }
                    }
                }
            }
        }
        else if(dir=="up")
        {
            for(int j=1;j<=n;j++)
            {
                int cnt = 1;
                for(int k=1;k<=n;k++)
                {
                    if(cnt>n)
                    {
                        s[k][j] = 0;
                    }
                    else
                    {
                        if(s[cnt][j]==0)
                        {
                            bool flag = false;
                            for(int kk=cnt;kk<=n;kk++)
                            {
                                if(s[kk][j]!=0)
                                {
                                    cnt = kk;
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag)cnt = n+1;
                        }

                        int cntpp = n+1;
                        for(int kk=cnt+1;kk<=n;kk++)
                        {
                            if(s[kk][j]!=0)
                            {
                                cntpp = kk;
                                break;
                            }
                        }
                        if(s[cnt][j]==s[cntpp][j])
                        {
                            s[k][j] = s[cnt][j]*2;
                            cnt = cntpp + 1;
                        }
                        else
                        {
                            s[k][j] = s[cnt][j];
                            cnt = cntpp;
                        }
                    }
                }
            }
        }
        else if(dir=="down")
        {
            for(int j=1;j<=n;j++)
            {
                int cnt = n;
                for(int k=n;k>=1;k--)
                {
                    if(cnt<1)
                    {
                        s[k][j] = 0;
                    }
                    else
                    {
                        if(s[cnt][j]==0)
                        {
                            bool flag = false;
                            for(int kk=cnt;kk>=1;kk--)
                            {
                                if(s[kk][j]!=0)
                                {
                                    cnt = kk;
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag)cnt = 0;
                        }

                        int cntpp = 0;
                        for(int kk=cnt-1;kk>=1;kk--)
                        {
                            if(s[kk][j]!=0)
                            {
                                cntpp = kk;
                                break;
                            }
                        }
                        if(s[cnt][j]==s[cntpp][j])
                        {
                            s[k][j] = s[cnt][j]*2;
                            cnt = cntpp - 1;
                        }
                        else
                        {
                            s[k][j] = s[cnt][j];
                            cnt = cntpp;
                        }
                    }

                }
            }
        }

        cout<<"Case #"<<i<<":"<<endl;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)cout<<s[j][k]<<' ';
            cout<<endl;
        }

    }
}
