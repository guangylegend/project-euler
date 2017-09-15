#include<stdio.h>
#include<cstring>
#include<iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int sum[10000];
double num[4];


double opt(double x,double y,int op)
{
    if(op==1)return x+y;
    if(op==2)return x*y;
    if(op==3)return x-y;
    if(op==4)return y-x;
    if(op==5)
    {
        if(fabs(y)<1e-8)return -10000;
        else return x/y;
    }
    if(op==6)
    {
        if(fabs(x)<1e-8)return -10000;
        else return y/x;
    }
}

int main()
{
    int k=1;

    for(int i1=1;i1<=6;i1++)
    {
        for(int i2=i1+1;i2<=7;i2++)
        {
            for(int i3=i2+1;i3<=8;i3++)
            {
                for(int i4=i3+1;i4<=9;i4++)
                {
                    memset(sum,0,sizeof(sum));
                    int op[3];
                    num[0]=i1;
                    num[1]=i2;
                    num[2]=i3;
                    num[3]=i4;
                    while(next_permutation(num,num+4))
                    {
                        for(int j1=1;j1<=4;j1++)
                        {
                            for(int j2=1;j2<=4;j2++)
                            {
                                for(int j3=1;j3<=4;j3++)
                                {

                                    op[0]=j1;
                                    op[1]=j2;
                                    op[2]=j3;
                                    double s=0,t=0;
                                    s=opt(num[0],num[1],op[0]);
                                    if(fabs(s+10000)<1e-8)break;
                                    t=opt(num[2],num[3],op[1]);
                                    if(fabs(t+10000)<1e-8)break;
                                    s=opt(s,t,op[2]);
                                    if(((int)s==s)&&s>0)sum[(int)s]=1;

                                }
                            }
                        }
                        for(int j1=1;j1<=6;j1++)
                        {
                            for(int j2=1;j2<=6;j2++)
                            {
                                for(int j3=1;j3<=6;j3++)
                                {

                                    op[0]=j1;
                                    op[1]=j2;
                                    op[2]=j3;
                                    double s=0;
                                    s = opt(num[0],num[1],op[0]);
                                    if(fabs(s+10000)<1e-8)break;
                                    s = opt(s,num[2],op[1]);
                                    if(fabs(s+10000)<1e-8)break;
                                    s = opt(s,num[3],op[2]);
                                    if(fabs(s+10000)<1e-8)break;
                                    if(((int)s==s)&&s>0)sum[(int)s]=1;

                                }
                            }
                        }

                    }

                    for(int i=1;i<=10000;i++)
                    {
                        if(sum[i]==0)
                        {
                            if(i>k)
                            {
                                k=i;
                                cout<<i1<<' '<<i2<<' '<<i3<<' '<<i4<<' ';
                                cout<<k<<endl;
                            }

                            break;
                        }
                    }



                }
            }
        }
    }

}
