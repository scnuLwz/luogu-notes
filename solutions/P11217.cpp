#include<bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;

const int N = 2e6 + 10;
int n,q,w,a[N];

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int sum[N<<2],tag[N<<2];

inline void up(int p){
	sum[p]=sum[ls]+sum[rs];
}
void build(int p,int l,int r){
	if(l==r){
		sum[p]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	up(p);
}
inline void push_d(int p,int l,int r){
	if(tag[p]){
		int mid=l+r>>1;
		tag[rs]+=tag[p];tag[ls]+=tag[p];
		sum[ls]+=tag[p]*(mid-l+1);sum[rs]+=tag[p]*(r-mid);
		tag[p]=0;
		return;
	}
}
inline void update(int p,int l,int r,int x,int y,int k){
    if(l>=x&&r<=y){
    	sum[p]+=k*(r-l+1);
    	tag[p]+=k;
    	return;
	}	
	if(l>y||r<x)  return;
	int mid=l+r>>1;push_d(p,l,r);
	update(ls,l,mid,x,y,k);update(rs,mid+1,r,x,y,k);
	up(p);
}
inline int query(int p,int l,int r,int x,int y){
	if(l>=x&&r<=y)  return sum[p];
	int mid=l+r>>1,ans=0;push_d(p,l,r);
	if(x<=mid)  ans+=query(ls,l,mid,x,y);
	if(y>mid)  ans+=query(rs,mid+1,r,x,y);
	return ans;
}
inline void print(int x){
	if(x>9)  print(x/10);
	putchar(x%10+'0');
}
inline int ask(int p,int l,int r,int res,int lev){
	if(l==r)  return l;
	int mid=l+r>>1;push_d(p,l,r);
	if(res>sum[ls]*lev)  return ask(rs,mid+1,r,res-sum[ls]*lev,lev);
	else return ask(ls,l,mid,res,lev);
}
void solve(int L,int R,int val){
	update(1,1,n,L,R,val);int sum=query(1,1,n,1,n);
	int k=1;int blo=w,s=0,ans=0;
	while(1){
		if(blo<=sum)  break;
		blo-=sum;
		sum<<=1;ans+=n;
		k<<=1;
	}
   // print(s);print(w);cout<<endl;
    print(ask(1,1,n,blo,k)+ans-1);cout<<'\n';
}
signed main(){
//	freopen("mx1.in","r",stdin);
//	freopen("mx.out","w",stdout);
	n=read();q=read();w=read();
	for(int i=1;i<=n;i++)  a[i]=read();
	build(1,1,n);
	for(int x,y,val;q;q--){
		x=read();y=read();val=read();
		solve(x,y,val);
	}
	return 0;
}