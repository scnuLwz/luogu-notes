#include<bits/stdc++.h>
#define rep(i,x,y)  for(int i=x;i<=y;i++)
#define int long long
using namespace std;

const int N = 1e6 + 10 , mod = 10007;

int w[N],n,d[N],f[N],root,sum[N],ans;
vector<int> v[N];

void dfs(int p,int fa){
	for(int i:v[p]){
		if(i==fa)  continue;
		dfs(i,p);
		if(f[i]<f[p]){
			f[p]=f[i];//minw[p]=i;
		}
	}
}

void solve(int p,int fa){
	for(int i:v[p]){
		if(i==fa)  continue;
		solve(i,p);
		sum[p]+=sum[i];
	}
	if(sum[p]<d[p]){
		ans+=(d[p]-sum[p])*f[p];
		sum[p]=d[p];
	}
}
signed main(){
	cin>>n;
	rep(i,1,n){
		int x;
		cin>>x>>d[i]>>w[i];f[i]=w[i];//sum[i]=d[i];
		if(x==-1)  root=i;
		else{
		    v[i].push_back(x);
		    v[x].push_back(i);
		} 
	}
	dfs(root,0);
	solve(root,0);
	cout<<ans;
	return 0;
}