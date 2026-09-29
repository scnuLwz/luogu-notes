#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1010;
char a[N][N];
int n,m,bx,by,ex,ey,ans=1e9,f[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool v[N][N];
int dis1[N][N],dis2[N][N];
struct node{
	int x,y,bs;
};
void bfs(bool k){
	queue<node> q;memset(v,false,sizeof v);
	if(k==0)
	{
		q.push({bx,by,0});
	    v[bx][by]=true;
	    memset(dis1,127,sizeof dis1);
		dis1[bx][by]=0;
	}
	else{
		q.push({ex,ey,0});
		v[ex][ey]=true;
		memset(dis2,127,sizeof dis2);
		dis2[ex][ey]=0;
	}
	while(!q.empty()){
		node t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=f[i][0]+t.x,yy=f[i][1]+t.y;
			if(xx<1||xx>n||yy<1||yy>m||v[xx][yy]==true||a[xx][yy]=='1')  continue;
			v[xx][yy]=true;
			if(k==0){
			    dis1[xx][yy]=dis1[t.x][t.y]+1;
			    q.push({xx,yy,t.bs+1});
			} 
			else
			{
				dis2[xx][yy]=dis2[t.x][t.y]+1;
				q.push({xx,yy,t.bs+1});
			} 
		}
	}
}
signed main(){
	cin>>n>>m;
	swap(n,m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	cin>>a[i][j];
	  	if(a[i][j]=='2')  bx=i,by=j;
	  	if(a[i][j]=='3')  ex=i,ey=j;
	  }
	bfs(0);bfs(1);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    if(a[i][j]=='4'&&dis1[i][j]<=1e9&&dis2[i][j]<=1e9)
	      ans=min(ans,dis1[i][j]+dis2[i][j]);
	return cout<<ans,0;
}