#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 8e6 + 10;

int a[N],n,q;
struct node{
	int tag1,tag2,maxn;
	bool eql;
}tr[N];
int ls(int x){return x*2;}
int rs(int x){return x*2+1;}
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void build(int p,int l,int r){
	tr[p].maxn=-1e18;
	if(l==r){
		tr[p].maxn=a[l];
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);build(rs(p),mid+1,r);
	tr[p].maxn=max(tr[ls(p)].maxn,tr[rs(p)].maxn);
} 
void push_d(int x){
	if(tr[x].eql){
		tr[ls(x)].eql=tr[rs(x)].eql=1;
		tr[ls(x)].tag1=tr[rs(x)].tag1=tr[x].tag1;
		tr[ls(x)].tag2=tr[rs(x)].tag2=tr[x].tag2;
		tr[ls(x)].maxn=tr[x].tag1+tr[x].tag2;
		tr[rs(x)].maxn=tr[x].tag1+tr[x].tag2;
	}
	else{
		tr[ls(x)].tag2+=tr[x].tag2;
		tr[rs(x)].tag2+=tr[x].tag2;
		tr[ls(x)].maxn+=tr[x].tag2;
		tr[rs(x)].maxn+=tr[x].tag2;
	}
	tr[x].tag1=tr[x].tag2=tr[x].eql=0;
	return;
}
void change(int p,int l,int r,int x,int y,int k){
	if(l>=x&&r<=y){
		tr[p].tag1=k;
		tr[p].maxn=k;
		tr[p].eql=1;
		tr[p].tag2=0;
		push_d(p);
		return;
	}
	int mid=l+r>>1;
	push_d(p);
	if(x<=mid)  change(ls(p),l,mid,x,y,k);
	if(y>mid)  change(rs(p),mid+1,r,x,y,k);
	tr[p].maxn=max(tr[ls(p)].maxn,tr[rs(p)].maxn);
}
void update(int p,int l,int r,int x,int y,int k){
	if(l>=x&&r<=y){
		tr[p].tag2+=k;
		tr[p].maxn+=k;
		push_d(p);
		return;
	}
	int mid=l+r>>1;push_d(p);
	if(x<=mid)  update(ls(p),l,mid,x,y,k);
	if(y>mid)  update(rs(p),mid+1,r,x,y,k);
	tr[p].maxn=max(tr[ls(p)].maxn,tr[rs(p)].maxn);
}
int query(int p,int l,int r,int x,int y){
	if(l>=x&&r<=y)  return tr[p].maxn;
	push_d(p);
	int mid=l+r>>1,ans=-1e18;
	if(x<=mid)  ans=max(ans,query(ls(p),l,mid,x,y));
	if(y>mid)  ans=max(ans,query(rs(p),mid+1,r,x,y));
	return ans;
}
signed main(){
	n=read();q=read();
	for(int i=1;i<=n;++i)  a[i]=read();
	build(1,1,n);
	for(int i=1,opt,x,y,k;i<=q;i++){
		opt=read();x=read();y=read();
		if(opt==1)  k=read(),change(1,1,n,x,y,k);
	    else if(opt==2)  k=read(),update(1,1,n,x,y,k);
	    else
		  cout<<query(1,1,n,x,y)<<endl;
	}
	return 0;
}