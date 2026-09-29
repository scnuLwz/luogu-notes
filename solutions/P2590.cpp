#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long

using namespace std;

const int N = 1e5 + 10 , INF = 1e9 + 7;

int top[N],n,m,rt,mod,son[N],dep[N],rnk[N],fa[N],dfn[N],cnt;
int val[N],siz[N];
vector<int> v[N];

struct SegTree{
	int sum[N<<2],maxn[N<<2];
	void up(int p){
		sum[p]=sum[ls]+sum[rs];
		maxn[p]=max(maxn[ls],maxn[rs]);
	}
	void build(int p,int l,int r){
		if(l==r){
			sum[p]=maxn[p]=val[rnk[l]];
			return;
		}
		int mid=l+r>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		up(p);
	}
	int query_max(int p,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			return maxn[p]; 
		}
		if(l>y||r<x)  return -INF;  
		int mid=l+r>>1;
		return max(query_max(ls,l,mid,x,y),query_max(rs,mid+1,r,x,y));
	}
	int query_sum(int p,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			return sum[p]; 
		}
		if(l>y||r<x)  return 0;  
		int mid=l+r>>1;
		return query_sum(ls,l,mid,x,y)+query_sum(rs,mid+1,r,x,y);
	}
	void upd(int p,int l,int r,int x,int k){
		if(l==r){
			maxn[p]=sum[p]=k;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)  upd(ls,l,mid,x,k);
		else  upd(rs,mid+1,r,x,k); 
		up(p);
	}
}st;
void dfs1(int p){
	siz[p]=1;son[p]=-1;
	for(int t:v[p]){
		if(!dep[t]){
			dep[t]=dep[p]+1;
			fa[t]=p;
			dfs1(t);
			siz[p]+=siz[t];
			if(son[p]==-1||(siz[t]>siz[son[p]]))
			  son[p]=t;
		}
	}
}
void dfs2(int p,int t){
	top[p]=t;dfn[p]=++cnt;rnk[cnt]=p;
	if(son[p]==-1)  return;
	dfs2(son[p],t);
	for(int to:v[p]){
		if(to!=son[p]&&to!=fa[p])
		  dfs2(to,to);
	}
}
int ser_max(int x,int y){
	int res=-INF,fx=top[x],fy=top[y];
	while(fx!=fy){
		if(dep[fx]>=dep[fy])
		  res=max(res,st.query_max(1,1,n,dfn[fx],dfn[x])),x=fa[fx];
		else res=max(res,st.query_max(1,1,n,dfn[fy],dfn[y])),y=fa[fy];
		fx=top[x],fy=top[y];
	}
	if(dfn[x]<dfn[y])  res=max(res,st.query_max(1,1,n,dfn[x],dfn[y]));
	else res=max(res,st.query_max(1,1,n,dfn[y],dfn[x]));
	return res;
}
int ser_sum(int x,int y){
	int res=0,fx=top[x],fy=top[y];
	while(fx!=fy){
		if(dep[fx]>=dep[fy])
		  res+=st.query_sum(1,1,n,dfn[fx],dfn[x]),x=fa[fx];
		else res+=st.query_sum(1,1,n,dfn[fy],dfn[y]),y=fa[fy];
		fx=top[x],fy=top[y];
	}
	if(dfn[x]<dfn[y])  res+=st.query_sum(1,1,n,dfn[x],dfn[y]);
	else res+=st.query_sum(1,1,n,dfn[y],dfn[x]);
	return res;
}
signed main(){
    cin>>n;
    for(int i=1,x,y;i<n;i++){
    	cin>>x>>y;
		v[x].emplace_back(y);
    	v[y].emplace_back(x);
	}
	for(int i=1;i<=n;i++)  cin>>val[i];
	dep[1]=1;dfs1(1);dfs2(1,1);
	st.build(1,1,n);
	int Q;cin>>Q;
	while(Q--){
		string opt;int x,y;
		cin>>opt>>x>>y;
		if(opt=="CHANGE")  st.upd(1,1,n,dfn[x],y);
		else if(opt=="QMAX")  cout<<ser_max(x,y)<<endl;
		else cout<<ser_sum(x,y)<<endl;
	}
    return 0;
}