#include"mymath.h"

int calc(int m,int n,int l,int k)
{
    return 2 * ( m * n + n * l + l * m ) +
        4 * ( m + n + l ) * ( k - 1 ) +
        4 * ( k - 1 ) * ( k - 2 ) ;
}


int main()
{
    for(int n=2;n<=50000;n++)
    {
        int cnt=0;
        for(int i=1;i<=n/2;i++)
            for(int j=i;i*j<=n/2;j++)
                for(int k=j;j*k+i*j+i*k<=n/2;k++)
                    for(int l=1;l*l*4<=n;l++){
                        int s = calc(i,j,k,l);
                        if(s>n)break;
                        if(s==n)
                        {
                            cnt++;
                        }
                    }
        if(n%1000==0)cout<<n<<endl;
        if(cnt==1000)cout<<n<<endl;
    }


}
