#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long

using namespace std;

const int N = 1e5 + 10 , INF = 1e9 + 7;

int res,top[N],n,m,rt,son[N],dep[N],wt[N],fa[N],dfn[N],cnt;
int val[N],siz[N];
vector<int> v[N];

struct SegTree{
	int sum[N<<2],tag[N<<2];
	void up(int p){
		sum[p]=(sum[ls]+sum[rs]);
	}
	void push_d(int p,int l,int r){
		int mid=l+r>>1;
		if(tag[p]){
			tag[ls]+=tag[p];tag[rs]+=tag[p];
			sum[ls]+=(mid-l+1)*tag[p];
			sum[rs]+=(r-mid)*tag[p];
			tag[p]=0;
		}
	}
	void query_sum(int p,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			res+=sum[p];return; 
		}
		if(l>y||r<x)  return;
		push_d(p,l,r);
		int mid=l+r>>1;
		if(x<=mid)  query_sum(ls,l,mid,x,y);
		if(y>mid)  query_sum(rs,mid+1,r,x,y);
		up(p);
	}
	void upd(int p,int l,int r,int x,int y,int k){
		if(l>y||r<x)  return;
		if(x<=l&&r<=y){
			sum[p]+=(r-l+1)*k;
			tag[p]+=k;
			return;
		}
		int mid=l+r>>1;
		push_d(p,l,r);
		if(x<=mid)  upd(ls,l,mid,x,y,k);
		if(y>mid)  upd(rs,mid+1,r,x,y,k); 
		up(p);
	}
}st;
inline void dfs1(int x,int f,int deep){
    dep[x]=deep;
    fa[x]=f;
    siz[x]=1;
    int maxson=-1;
    for(int p:v[x]){
        if(p==f)continue;
        dfs1(p,x,deep+1);
        siz[x]+=siz[p];
        if(siz[p]>maxson)son[x]=p,maxson=siz[p];
    }
}
inline void dfs2(int x,int topf){
    dfn[x]=++cnt;
    top[x]=topf;
    if(!son[x])return;
    dfs2(son[x],topf);
    for(int p:v[x]){
        if(p==fa[x]||p==son[x])continue;
        dfs2(p,p);//对于每一个轻儿子都有一条从它自己开始的链 
    }
}
void upd_range(int x,int y,int k){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])  swap(x,y);
		st.upd(1,1,n,dfn[top[x]],dfn[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])  swap(x,y);
	st.upd(1,1,n,dfn[x],dfn[y],k);
}
int ser_son(int x){
	res=0;
	st.query_sum(1,1,n,dfn[x],dfn[x]+siz[x]-1);
	return res;
}
signed main(){
    cin>>n;
    for(int i=1,x,y;i<n;i++){
    	cin>>x>>y;
    	v[x].emplace_back(y);
    	v[y].emplace_back(x);
	}
	dfs1(0,-1,1);dfs2(0,0);
	int Q;cin>>Q;
	for(int x,y,z;Q;Q--){
		char opt;
		cin>>opt>>x;
		if(opt=='A'){
			cin>>y>>z;
			upd_range(x,y,z);
		}
		else if(opt=='Q'){
			cout<<ser_son(x)<<endl;
		}
	}
    return 0;
}