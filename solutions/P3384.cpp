#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long

using namespace std;

const int N = 1e5 + 10 , INF = 1e9 + 7;

int res,top[N],n,m,rt,mod,son[N],dep[N],wt[N],fa[N],dfn[N],cnt;
int val[N],siz[N];
vector<int> v[N];

struct SegTree{
	int sum[N<<2],tag[N<<2];
	void up(int p){
		sum[p]=(sum[ls]+sum[rs])%mod;
	}
	void build(int p,int l,int r){
		if(l==r){
		//	cout<<p<<" ccf "<<wt[l]<<endl;
			sum[p]=wt[l]%mod;
			return;
		}
		int mid=l+r>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		up(p);
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
			res+=sum[p];res%=mod;return; 
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
    wt[cnt]=val[x]; 
    top[x]=topf;
    if(!son[x])return;
    dfs2(son[x],topf);
    for(int p:v[x]){
        if(p==fa[x]||p==son[x])continue;
        dfs2(p,p);//对于每一个轻儿子都有一条从它自己开始的链 
    }
}
void upd_son(int x,int k){
	st.upd(1,1,n,dfn[x],dfn[x]+siz[x]-1,k);
}
void upd_range(int x,int y,int k){
	k%=mod;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])  swap(x,y);
		st.upd(1,1,n,dfn[top[x]],dfn[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])  swap(x,y);
	st.upd(1,1,n,dfn[x],dfn[y],k);
}
int ser_range(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])  swap(x,y);
		res=0;
		st.query_sum(1,1,n,dfn[top[x]],dfn[x]);
		ans+=res;ans%=mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])  swap(x,y);
	res=0;st.query_sum(1,1,n,dfn[x],dfn[y]);
	ans+=res;
	return ans%mod;
}
int ser_son(int x){
	res=0;
	st.query_sum(1,1,n,dfn[x],dfn[x]+siz[x]-1);
	return res%mod;
}
signed main(){
    cin>>n>>m>>rt>>mod;
    for(int i=1;i<=n;i++)  cin>>val[i];
    for(int i=1,x,y;i<n;i++){
    	cin>>x>>y;
    	v[x].emplace_back(y);
    	v[y].emplace_back(x);
	}
	dfs1(rt,0,1);dfs2(rt,rt);
	st.build(1,1,n);
	for(int i=1,opt,x,y,z;i<=m;i++){
		cin>>opt>>x;
		if(opt==1){
			cin>>y>>z;
			upd_range(x,y,z);
		}
		else if(opt==2){
			cin>>y;cout<<ser_range(x,y)%mod<<endl;
		}
		else if(opt==3){
			cin>>y;
			upd_son(x,y);
		}
		else  cout<<ser_son(x)%mod<<endl;
	}
    return 0;
}