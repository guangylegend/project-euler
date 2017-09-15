#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define RR 729
#define CC 324
#define INF 1000000000
int mem1[81+1];
int mem2[81+1];
int *mem = mem1;
char ch[81+1];
int cnt[CC+1];
int scnt=0; //solution count
int sum=0;
int tcnt=0;

struct node {
    int r,c;
    node *up;
    node *down;
    node *left;
    node *right;
}head,all[RR*CC+99],row[RR],col[CC];int all_t;

inline void link(int r,int c) {
    cnt[c]++;
    node *t=&all[all_t++];
    t->r=r;
    t->c=c;
    t->left=&row[r];
    t->right=row[r].right;
    t->left->right=t;
    t->right->left=t;
    t->up=&col[c];
    t->down=col[c].down;
    t->up->down=t;
    t->down->up=t;
}

inline void remove(int c) {
    node *t,*tt;
    col[c].right->left=col[c].left;
    col[c].left->right=col[c].right;
    for(t=col[c].down;t!=&col[c];t=t->down) {
        for(tt=t->right;tt!=t;tt=tt->right) {
            cnt[tt->c]--;
            tt->up->down=tt->down;
            tt->down->up=tt->up;
        }
        t->left->right=t->right;
        t->right->left=t->left;
    }
}

inline void resume(int c) {
    node *t,*tt;
    for(t=col[c].down;t!=&col[c];t=t->down) {
        t->right->left=t;
        t->left->right=t;
        for(tt=t->left;tt!=t;tt=tt->left) {
            cnt[tt->c]++;
            tt->down->up=tt;
            tt->up->down=tt;
        }
    }
    col[c].left->right=&col[c];
    col[c].right->left=&col[c];
}

void print_solution(int*m){

  int ans[81];
  for(int i=1;i<=81;i++) {
    int t=m[i]/9%81;
    int val=m[i]%9+1;
    ans[t]=val;
  }
  for(int i=0;i<81;i++)
    printf("%d",ans[i]);
    sum+=ans[0]*100+ans[1]*10+ans[2];
    tcnt++;
    cout<<endl<<tcnt<<endl;
    cout<<sum<<endl;


}

void solve(int k)
{
    if(head.right==&head) {//got one solution
      if (!scnt) {
        memcpy(mem2, mem1, sizeof(mem1));
        //memset(mem,0,sizeof(mem));
        //mem = mem2;

      }
      scnt++;
      return;
    }
    node*t,*tt;
    int min=INF,tc;
    for(t=head.right;t!=&head;t=t->right) {
        if(cnt[t->c]<min) {
            min=cnt[t->c];
            tc=t->c;
            if(min<=1)break;
        }
    }
    remove(tc);
    for(t=col[tc].down;t!=&col[tc];t=t->down) {
        mem[k]=t->r;
        t->left->right=t;
        for(tt=t->right;tt!=t;tt=tt->right) {
            remove(tt->c);
        }
        t->left->right=t->right;
        solve(k+1);
        if (scnt >= 2)
          return;
        t->right->left=t;
        for(tt=t->left;tt!=t;tt=tt->left) {
            resume(tt->c);
        }
        t->right->left=t->left;
    }
    resume(tc);
    return;
}
void sol()
{
    scnt=0;
    all_t=1;

  memset(cnt,0,sizeof(cnt));
  head.left=&head;
  head.right=&head;
  head.up=&head;
  head.down=&head;
  head.r=RR;
  head.c=CC;
  for(int i=0;i<CC;i++) {
    col[i].c=i;
    col[i].r=RR;
    col[i].up=&col[i];
    col[i].down=&col[i];
    col[i].left=&head;
    col[i].right=head.right;
    col[i].left->right=&col[i];
    col[i].right->left=&col[i];
  }
  for(int i=0;i<RR;i++) {
    row[i].r=i;
    row[i].c=CC;
    row[i].left=&row[i];
    row[i].right=&row[i];
    row[i].up=&head;
    row[i].down=head.down;
    row[i].up->down=&row[i];
    row[i].down->up=&row[i];
  }
  for(int i=0;i<RR;i++) {
    int r=i/9/9%9;
    int c=i/9%9;
    int val=i%9+1;
    if(ch[r*9+c]=='.'||ch[r*9+c]==val+'0') {
      link(i,r*9+val-1);
      link(i,81+c*9+val-1);
      int tr=r/3;
      int tc=c/3;
      link(i,162+(tr*3+tc)*9+val-1);
      link(i,243+r*9+c);
    }
  }
  for(int i=0;i<RR;i++) {
    row[i].left->right=row[i].right;
    row[i].right->left=row[i].left;
  }
  solve(1);
  printf("\n");

    print_solution(mem1);


}

int main() {


  freopen("1.txt","r",stdin);
  int kkk=0;
  char tmp;
  int cntt=0;
  while(scanf(" %c",&tmp)==1)
  {
      if(tmp=='G')
      {
          char t[1000];
          gets(t);
          cntt=0;
      }
      else
      {
          if(tmp=='0')tmp='.';
          ch[cntt]=tmp;
          cntt++;
          cout<<tmp;
      }
      if(cntt==81)
      {
          ch[cntt]='\0';
          sol();

        }
    }




}
