#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(3)
#define rep(i,x,y)  for(int i=x;i<=y;i++) 
using namespace std;

const int N = 110;

int n,m,f[N][N][N],dis[N][N];
vector<int> v[N]; 

void solve(){
	rep(S,1,63){
		rep(k,1,n)
		  rep(i,1,n)
		    rep(j,1,n)
		      f[i][j][S]|=(f[i][k][S-1]&&f[k][j][S-1]);
	}
	rep(S,0,63)
	  rep(i,1,n)
	    rep(j,1,n)
	      if(f[i][j][S]==1)
	        dis[i][j]=1;
	rep(k,1,n)
	  rep(i,1,n)
	    rep(j,1,n)
	      dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	cout<<dis[1][n];
}
signed main(){
	memset(dis,0x3f,sizeof dis);
	cin>>n>>m;
	rep(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);v[y].push_back(x);
	    f[x][y][0]=1;
	}
	solve();
	return 0;
}