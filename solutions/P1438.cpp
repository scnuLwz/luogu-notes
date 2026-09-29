#include<bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;

const int N = 1e6 + 10 , INF = -1e9;
int n,m,a[N];

struct SEG{
	int sum[N<<2],tag[N<<2];
	void up(int p){
		sum[p]=sum[ls]+sum[rs];
	}
	void push_d(int p,int l,int r){
		if(tag[p]){
			int mid=l+r>>1;
			tag[ls]+=tag[p];
			tag[rs]+=tag[p];
			sum[ls]+=tag[p]*(mid-l+1);
			sum[rs]+=tag[p]*(r-mid);
			tag[p]=0;return;
		}
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
	void update(int p,int l,int r,int x,int y,int k){
		if(x<=l&&y>=r){
			sum[p]+=k*(r-l+1);
			tag[p]+=k;
			return;
		}
		if(l>y||r<x)  return;
		int mid=l+r>>1;
		push_d(p,l,r);
		update(ls,l,mid,x,y,k);update(rs,mid+1,r,x,y,k);
		up(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(x<=l&&y>=r)  return sum[p];
	   // if(l>y||r<x)  return INF;
	    int mid=l+r>>1;
	    push_d(p,l,r);int ans=0;
	    if(x<=mid)  ans+=query(ls,l,mid,x,y);
		if(y>mid)  ans+=query(rs,mid+1,r,x,y);
		return ans;
	}
}st;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=n;i>=1;i--)  a[i]=a[i]-a[i-1];
	st.build(1,1,n);
//	cout<<st.query(1,1,n,1,3);
	for(int i=1,opt,x,l,r,k,d;i<=m;i++){
		cin>>opt;
		if(opt==1){
			cin>>l>>r>>k>>d;
			//al+=k;ar+1-=(r-l)*d+k//al~r+=d
			st.update(1,1,n,l,l,k);
			if(r+1<=n)  st.update(1,1,n,r+1,r+1,-(r-l)*d-k);
			st.update(1,1,n,l+1,r,d);
		}
		else{
			cin>>x;
			cout<<st.query(1,1,n,1,x)<<endl;
		}  
	}
	return 0;
}