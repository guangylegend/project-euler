#include<iostream>
#include<cstring>
using namespace std;

int digit[10];
int papapa[100000000];

bool test(int n)
{
    memset(digit,0,sizeof(digit));
    int cnt=0;
    while(n!=0)
    {
        digit[cnt]=n%10;
        cnt++;
        n/=10;
    }
    for(int i=0;i<=(cnt-1)/2;i++)
        if(digit[i]!=digit[cnt-1-i])return false;
    return true;
}

int main()
{
    memset(papapa,0,sizeof(papapa));
    long long int tot = 0;
    for(int i=1;i<=10000;i++)
    {
        for(int j=i+1;j<=10000;j++)
        {
            //int sum = j*(j+1)*(2*j+1)/6-(i-1)*i*(2*i-1)/6;
            int sum=0;
            for(int k=i;k<=j;k++)sum+=k*k;
            if(sum>=100000000)break;
            if(test(sum))
            {
                if(papapa[sum]!=0)continue;
                papapa[sum]=1;
                tot+=sum;
                //cout<<sum<<endl;
            }
        }
    }
    cout<<tot<<endl;
}
