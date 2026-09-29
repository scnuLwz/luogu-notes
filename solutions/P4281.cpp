#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int siz[N],n,m,dep[N],fa[N],top[N],son[N],id;
vector<int> v[N];

void dfs1(int p,int F,int deep){
	siz[p]=1;fa[p]=F;dep[p]=deep;
	int maxn=-1;
	for(int t:v[p]){
		if(t==F)  continue;
		dfs1(t,p,deep+1);
		siz[p]+=siz[t];
		if(son[p]>maxn){
			son[p]=t;
			maxn=son[p];
		}
	}
}
void dfs2(int p,int topf){
	top[p]=topf;
	if(!son[p])  return;
	dfs2(son[p],topf);
	for(int t:v[p]){
		if(t==fa[p]||son[p]==t)  continue;
		dfs2(t,t);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])  swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	dfs1(1,0,1);dfs2(1,1);
	for(int x,y,z;m;m--){
		cin>>x>>y>>z;int lca1=lca(x,y),lca2=lca(x,z),lca3=lca(y,z);
		int ans=dis(x,y)+dis(lca1,z);id=lca1;
		if(dis(x,z)+dis(lca2,y)<ans)  ans=dis(x,z)+dis(lca2,y),id=lca2;
		if(dis(y,z)+dis(lca3,x)<ans)  ans=dis(y,z)+dis(lca3,x),id=lca3;
		cout<<id<<" "<<ans<<endl;
	} 
	return 0;
}