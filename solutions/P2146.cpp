#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;

const int N = 1e5 + 10;
int n,dep[N],fa[N],siz[N],dfn[N],son[N],tag[N],top[N],tot;
vector<int> v[N];

struct SEG{
	int sum[N<<2],tag[N<<2];
	void up(int p){
		sum[p]=sum[ls]+sum[rs];
	}
	void push_d(int p,int l,int r){
		if(tag[p]!=-1){
			int mid=l+r>>1;
			tag[ls]=tag[p];tag[rs]=tag[p];
			sum[ls]=tag[p]*(mid-l+1);sum[rs]=tag[p]*(r-mid);
			tag[p]=-1;
		}
		return;
	}
	void update(int p,int l,int r,int x,int y,int k){
		if(x<=l&&r<=y){
			sum[p]=(r-l+1)*k;
			tag[p]=k;
			return;
		}
		if(l>y||r<x)  return;
		push_d(p,l,r);int mid=l+r>>1;
		if(x<=mid)  update(ls,l,mid,x,y,k);
		if(y>mid)  update(rs,mid+1,r,x,y,k);
		up(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(x<=l&&r<=y)  return sum[p];
		if(l>y||r<x)  return 0;
		push_d(p,l,r);int mid=l+r>>1,res=0;
		if(x<=mid)  res+=query(ls,l,mid,x,y);
		if(y>mid)  res+=query(rs,mid+1,r,x,y);
		return res;
	}
}st;
void dfs1(int p,int f,int deep){
	dep[p]=deep;fa[p]=f;siz[p]=1;
	int maxson=-1;
	for(int t:v[p]){
		if(t==f)  continue;
		dfs1(t,p,deep+1);
		siz[p]+=siz[t];
		if(siz[t]>maxson)  maxson=siz[t],son[p]=t;
	}
}

void dfs2(int p,int Tp){
	top[p]=Tp;dfn[p]=++tot;
	if(!son[p])  return;
	dfs2(son[p],Tp);
	for(int t:v[p]){
		if(fa[p]==t||t==son[p])  continue;
		dfs2(t,t);
	}
}
void upd1(int x,int y){
	while(top[x]!=top[y]){
		if(dep[x]<dep[y])  swap(x,y);
		st.update(1,1,n,dfn[top[x]],dfn[x],1);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])  swap(x,y);
	st.update(1,1,n,dfn[x],dfn[y],1);
}
void upd2(int x){
	st.update(1,1,n,dfn[x],dfn[x]+siz[x]-1,0);
}
int Qson(int x){
	return st.query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
}
int ser_sum(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[x]<dep[y])  swap(x,y);
		ans+=st.query(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])  swap(x,y);
	ans+=st.query(1,1,n,dfn[x],dfn[y]);
	return ans;
}
int main(){
	cin>>n;
	for(int i=1,x;i<n;i++){
		cin>>x;
		v[x].emplace_back(i);
		v[i].emplace_back(x);
	}
	dfs1(0,-1,1);dfs2(0,0);
	int Q;cin>>Q;
	for(int x;Q;Q--){
		string opt;cin>>opt>>x;
		if(opt=="install"){
			int lst=ser_sum(0,x);
			upd1(0,x);
			cout<<abs(ser_sum(0,x)-lst)<<endl;
		}
		else{
			int lst=Qson(x);
			upd2(x);
			cout<<abs(Qson(x)-lst)<<endl;
		}
	}
	return 0;
}