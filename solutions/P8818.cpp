#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10 , M = 1e9 + 10;

int n,m,Q,za[N],fa[N],b[N];
int g[N][30][2],fz[N][30][2],ff[N][30][2];

void B1(){
	int k=1;
	for(int j=1;j<=25;++j){
		for(int i=1;i<=n;i++){
			g[i][j][0]=g[i][j-1][0];
			g[i][j][1]=g[i][j-1][1];
			if(i+k<=n){
				g[i][j][0]=max(g[i][j][0],g[i+k][j-1][0]);
				g[i][j][1]=min(g[i][j][1],g[i+k][j-1][1]);
			}
		}
		k*=2;
	}
} 
void B2(){
	int k=1;
	for(int j=1;j<=25;++j){
		for(int i=1;i<=n;i++){
			fz[i][j][0]=fz[i][j-1][0];
			fz[i][j][1]=fz[i][j-1][1];
			ff[i][j][0]=ff[i][j-1][0];
			ff[i][j][1]=ff[i][j-1][1];
			if(i+k<=n){
				fz[i][j][0]=max(fz[i][j][0],fz[i+k][j-1][0]);
				fz[i][j][1]=min(fz[i][j][1],fz[i+k][j-1][1]);
				ff[i][j][0]=max(ff[i][j][0],ff[i+k][j-1][0]);
				ff[i][j][1]=min(ff[i][j][1],ff[i+k][j-1][1]);
			}
		}
		k*=2;
	}
}
int qb(int l,int r,string lx){
	int k=log2(r-l+1);
	if(l==r)  return g[l][0][0];
	if(lx=="max")  return max(g[l][k][0],g[r-(1<<k)+1][k][0]);
	else return min(g[l][k][1],g[r-(1<<k)+1][k][1]);
}
int qaz(int l,int r,string lx){
	int k=log2(r-l+1);
	if(l==r)  return fz[l][0][0];
	if(lx=="max")  return max(fz[l][k][0],fz[r-(1<<k)+1][k][0]);
	else return min(fz[l][k][1],fz[r-(1<<k)+1][k][1]);
}
int qaf(int l,int r,string lx){
	int k=log2(r-l+1);
	if(l==r)  return ff[l][0][0];
	if(lx=="max")  return max(ff[l][k][0],ff[r-(1<<k)+1][k][0]);
	else return min(ff[l][k][1],ff[r-(1<<k)+1][k][1]);
}
void solve(){
	while(Q--){
		int l1,l2,r1,r2;
		cin>>l1>>r1>>l2>>r2;
		int ans=-1e18;
		int MAXN=qb(l2,r2,"max"),MINN=qb(l2,r2,"min");
		int zMa=qaz(l1,r1,"max"),zMi=qaz(l1,r1,"min"),fMa=qaf(l1,r1,"max"),fMi=qaf(l1,r1,"min");
		if(abs(zMa)<M){
			ans=max(ans,zMa*MINN);ans=max(ans,zMi*MINN);
		}
		if(abs(fMa)<M){
			ans=max(ans,fMa*MAXN);ans=max(ans,fMi*MAXN);
		}
		cout<<ans<<endl;
	}
}
signed main(){
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)
	  for(int j=0;j<=25;j++){
	  	ff[i][j][0]=fz[i][j][0]=-M;fz[i][j][1]=ff[i][j][1]=M;
	  }
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x>=0)  fz[i][0][0]=fz[i][0][1]=x;
		else ff[i][0][0]=ff[i][0][1]=x;
	}
	for(int i=1;i<=m;++i){
		cin>>g[i][0][0];g[i][0][1]=g[i][0][0];
	}
	B1();B2();
	solve();
	return 0;
}