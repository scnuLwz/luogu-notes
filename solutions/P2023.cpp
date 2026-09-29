#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 10;

struct node{
	int add,mul;
}tag[N<<2];
int a[N],sum[N<<2],n,Q,mod;

void up(int p); 
void build(int p,int l,int r){
	if(l==r){
		sum[p]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	up(p);
} 
void push_d(int p,int l,int r){
	//对于sum区间和，我们先对儿子节点区间和×乘法标记+加法标记 ×区间长度
    //对于乘法标记，我们对儿子节点直接*乘法标记
    //对于加法标记，我们对儿子节点先*乘法标记++加法标记
	int ls=p<<1,rs=p<<1|1,mid=l+r>>1;
	sum[ls]=(sum[ls]*tag[p].mul%mod+tag[p].add*(mid-l+1)%mod)%mod;
	tag[ls].mul=(tag[ls].mul*tag[p].mul)%mod;
	tag[ls].add=(tag[ls].add*tag[p].mul%mod+tag[p].add)%mod;
	
	sum[rs]=(sum[rs]*tag[p].mul%mod+tag[p].add*(r-mid)%mod)%mod;
	tag[rs].mul=(tag[rs].mul*tag[p].mul)%mod;
	tag[rs].add=(tag[rs].add*tag[p].mul%mod+tag[p].add)%mod;
	
	tag[p]={0,1};
	return;
}
void up(int p){ 
	sum[p]=(sum[p<<1]+sum[p<<1|1])%mod;
}
void update_add(int p,int L,int R,int x,int y,int k){
	if(R<x||L>y)  return ;
	if(x<=L&&y>=R){
		sum[p]=(sum[p]+k*(R-L+1)%mod)%mod;
		tag[p].add=(tag[p].add+k)%mod;
		return;
	}
	int mid=L+R>>1,ls=p<<1,rs=p<<1|1;
	push_d(p,L,R);
	update_add(ls,L,mid,x,y,k);update_add(rs,mid+1,R,x,y,k);
	up(p);
}
void update_mul(int p,int L,int R,int x,int y,int k){
	if(R<x||L>y)  return ;
	if(x<=L&&y>=R){
		sum[p]=(sum[p]*k)%mod;
		tag[p].mul=(tag[p].mul*k)%mod;
		tag[p].add=(tag[p].add*k)%mod;
		return;
	}
	int mid=L+R>>1,ls=p<<1,rs=p<<1|1;
	push_d(p,L,R);
	update_mul(ls,L,mid,x,y,k);update_mul(rs,mid+1,R,x,y,k);
	up(p);
}
//void updata_mul(int x,int l,int r,int ll,int rr,int k){
//	int p=mod;
//    if(r<ll || l>rr) return;
//    if(l>=ll && r<=rr){
//        sum[x]=(sum[x]*k)%p;
//        tag[x].mul=(tag[x].mul*k)%p;
//        tag[x].add=(tag[x].add*k)%p;
//        return;
//    }
//    push_d(x,l,r);
//    int mid=(l+r)>>1;
//    updata_mul(x<<1,l,mid,ll,rr,k);
//    updata_mul(x<<1|1,mid+1,r,ll,rr,k);
//    up(x);
//}
//void updata_add(int x,int l,int r,int ll,int rr,int k){
//	int p=mod;
//    if(r<ll || l>rr) return;
//    if(l>=ll && r<=rr){
//        sum[x]=(sum[x]+k*(r-l+1)%p)%p;
//        tag[x].add=(tag[x].add+k)%p;
//        return;
//    }
//    push_d(x,l,r);
//    int mid=(l+r)>>1;
//    updata_add(x<<1,l,mid,ll,rr,k);
//    updata_add(x<<1|1,mid+1,r,ll,rr,k);
//    up(x);
//}
int query(int p,int L,int R,int x,int y){
	if(R<x||L>y)  return 0;
	if(x<=L&&y>=R)  return sum[p];
	int mid=L+R>>1,ls=p<<1,rs=p<<1|1;
	push_d(p,L,R);
	int ans=0;
	ans=(query(ls,L,mid,x,y)+query(rs,mid+1,R,x,y))%mod;
	return ans;
}
signed main(){
	cin>>n>>mod;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=1;i<=(n<<2);i++)  tag[i]={0,1};
	build(1,1,n);
	cin>>Q;
	for(int i=1,opt,l,r,k;i<=Q;i++){
		cin>>opt>>l>>r;
		if(opt==1){
			cin>>k;
			update_mul(1,1,n,l,r,k); 
		}
		if(opt==2){
			cin>>k;
			update_add(1,1,n,l,r,k);
		}
		if(opt==3){
			cout<<query(1,1,n,l,r)%mod<<endl;
		}
	}
	return 0;
}