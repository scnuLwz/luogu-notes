#include <bits/stdc++.h>

using namespace std;

const int N=1010;
int n , q , a[N][N],k[N][N];
int f[4][2]={{1,0},{0,1},{-1,0},{0,-1}},ans=1e8;
bool v[N][N];
void dfs(int x,int y,bool g,int s)
{
	if(s>=ans)  return;
	if(s>=k[x][y])  return;
	else k[x][y]=s;
	if(x==n&&y==n){
		ans=min(ans,s);
		return;
	}
	v[x][y] = true;
	for (int i=0;i<4;i++)
	{
		int xx=f[i][0]+x,yy=f[i][1]+y;
		if(xx<1||yy<1||xx>n||yy>n||v[xx][yy]||a[xx][yy]==0)  continue;
		if(a[xx][yy]!=a[x][y])
		  dfs(xx,yy,1,s+1);
		else if(a[xx][yy]==a[x][y]) dfs(xx,yy,1,s);
	} 
	
	if(g==1)
	{
	    for(int i=0;i<4;i++)
		{
			int xx=f[i][0]+x,yy=f[i][1]+y;
			if(xx<1||yy<1||xx>n||yy>n||v[xx][yy]||a[xx][yy]!=0)  continue;
			int t=a[xx][yy];
			a[xx][yy] = a[x][y];
			v[xx][yy] = true;
			dfs(xx,yy,0,s+2);
			a[xx][yy] = t;
			v[xx][yy] = false;
		}	
	}
	v[x][y] = false;
}
int main()
{
	cin >> n >> q;
	for(int i=1,x,y,c;i<=q;i++)
	{
		cin >> x >> y >> c;
		a[x][y] = c+1;
	}
	memset(k,127,sizeof(k));
	dfs(1,1,1,0);
	if(k[n][n]>90010000)  cout<<-1;
    else cout<<k[n][n];
	return 0;
} 