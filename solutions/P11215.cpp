#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3010 , M = 1e5 + 10;
int n,m,q,r,k,t[M],cnt,a[N][N],X[M],Y[M],ans,f[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[N][N];
bool chk2(int x,int y){
	if(vis[x][y])  return false;
	for(int i=0;i<4;i++){
		int xx=f[i][0]+x,yy=f[i][1]+y;
		if(vis[xx][yy])  return true;
		for(int j=0;j<4;j++){
			int xxx=f[j][0]+xx,yyy=f[j][1]+yy;
			if(vis[xxx][yyy])  return true;
		}
	}
	return false;
}
bool chk(int x,int y){
	if(vis[x][y])  return false;
	for(int i=0;i<4;i++){
		int xx=f[i][0]+x,yy=f[i][1]+y;
		if(xx<1||xx>n||yy<1||yy>m)  continue;
		if(vis[xx][yy])  return true;
	}
	return false;
}
bool hx(int x,int y){
	for(int i=0;i<4;i++){
		int xx=f[i][0]+x,yy=f[i][1]+y;
		if(xx<1||xx>n||yy<1||yy>m||vis[xx][yy]||a[xx][yy]<=0)  continue;
		if(a[xx][yy]-a[x][y]<=k)  return true;
	}
	return false;
}
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=f[i][0]+x,yy=f[i][1]+y;
		if(xx<1||xx>n||yy<1||yy>m)  continue;
	//	cout<<xx<<" "<<yy<<endl;
		if(chk(xx,yy)&&!a[xx][yy]){
			//cout<<xx<<" "<<yy<<endl;
			a[xx][yy]=a[x][y]+1;
			dfs(xx,yy);
		}
	}
}
signed main(){
	cin>>n>>m>>q>>r>>k;
	for(int ii=1,_x1,_y1,_x2,_y2;ii<=q;ii++){
		cin>>_x1>>_y1>>_x2>>_y2;
		for(int i=_x1;i<=_x2;i++)
		  for(int j=_y1;j<=_y2;j++)
		    vis[i][j]=true;
	}
	for(int i=1;i<=r;i++){
		cin>>t[i]>>X[i]>>Y[i];
		a[X[i]][Y[i]]=t[i];
	}
	for(int i=1;i<=r;i++){
		if(chk2(X[i],Y[i]))  dfs(X[i],Y[i]);
		else if(!hx(X[i],Y[i])) 
		  a[X[i]][Y[i]]=0;
	}  
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    if(a[i][j]>0)
	      ++ans;
	cout<<ans;
	return 0;
}