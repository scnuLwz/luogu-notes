#include<cstdio>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<cstring>
#define N 10000
#define M 100000
using namespace std;
stack<int> Stack;
queue<int> q;
struct line{
    int to,from,next;
}a[M];
int n,m,x,y,tot,in[N],ls[N],fl[N],cost[N],f[N],maxs,low[N],dfn[N],top,num,gt[N],an[N];
bool ins[N],v[N];
void addl(int x,int y,int tot)
{
    a[tot].to=y;
    a[tot].from=x;
    a[tot].next=ls[x];
    ls[x]=tot;
}
void tarjan(int x)
{
    ins[x]=true;
    dfn[x]=low[x]=++top;
    Stack.push(x);
    for (int i=ls[x];i;i=a[i].next)
      if (!dfn[a[i].to])
      {
        tarjan(a[i].to);
        low[x]=min(low[x],low[a[i].to]);
      }
      else if (ins[a[i].to])
        low[x]=min(low[x],dfn[a[i].to]);
    if (low[x]==dfn[x])
    {
        while (Stack.top()!=x)
        {
            int y=Stack.top();
            fl[y]=x;
            an[x]+=cost[y];//计算强联通权值和
            Stack.pop();
            ins[y]=0;
        }
        fl[x]=x;
        an[x]+=cost[x];//计算强联通权值和
        ins[x]=0;
        Stack.pop();
    }
}
void bfs()
{
    while (!q.empty())
    {
        int x=q.front();q.pop();
        for (int i=ls[x];i;i=a[i].next)
        {
            int y=a[i].to;
            f[y]=max(f[y],f[x]+an[y]);//dp
            maxs=max(maxs,f[y]);//求最大值
            if (!v[y]){
                q.push(y);
                v[y]=false;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&cost[i]);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        addl(x,y,i);//加边
    }
    for (int i=1;i<=n;i++)
      if (!dfn[i])
        tarjan(i);//求强联通
    memset(ls,0,sizeof(ls));//去除所有的边的连通（保留值的）
    for (int i=1;i<=m;i++)
    {
        x=a[i].from;y=a[i].to;
        if (fl[x]!=fl[y])//不在强联通中
        {
        //	cout<<x<<" "<<y<<endl;
            tot++;
            addl(fl[x],fl[y],tot);//连边
            in[fl[y]]++;//统计入度
        }
    }
    for (int i=1;i<=n;i++)
      if (fl[i]==i&&!in[i])//加入队列
      {
        q.push(i);
        v[i]=true;
        f[i]=an[i];
        maxs=max(maxs,f[i]);
      }
    bfs();
    printf("%d",maxs);
}