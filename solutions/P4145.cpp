#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int a[N],n,m,t[N<<2],ta[N<<2],ma[N<<2];

void build(int p,int l,int r){
	int mid=l+r>>1;
	if(l==r){
		t[p]=a[l];ma[p]=a[l];return;
	}  
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	t[p]=t[p<<1]+t[p<<1|1];
	ma[p]=max(ma[p<<1],ma[p<<1|1]);
}
void push_d(int p,int l,int r){
	int mid=l+r>>1;
	if(ta[p]){
		ta[p<<1]+=ta[p];
		ta[p<<1|1]+=ta[p];
		t[p<<1]+=ta[p<<1]*(mid-l+1);
		t[p<<1|1]+=ta[p<<1|1]*(r-mid);
		ta[p]=0;
	}
}
int ser(int p,int l,int r,int x,int y){
	if(l>=x&&r<=y)  return t[p];
	if(l>y||r<x)  return 0; 
	int mid=l+r>>1;
	push_d(p,l,r);
	return ser(p<<1,l,mid,x,y)+ser(p<<1|1,mid+1,r,x,y);
}
void update(int p,int l,int r,int x,int y){
	//x-y
	if(l>y||r<x)  return;
	if(l==r){
		t[p]=sqrt(t[p]);
		ma[p]=t[p];
		return;
	}
	push_d(p,l,r);
	int mid=l+r>>1;
	if(ma[p<<1]>1)
	  update(p<<1,l,mid,x,y);
	if(ma[p<<1|1]>1)
	  update(p<<1|1,mid+1,r,x,y);
	t[p]=t[p<<1]+t[p<<1|1];ma[p]=max(ma[p<<1],ma[p<<1|1]);
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    build(1,1,n);
    cin>>m;
    for(int i=1,k,l,r;i<=m;i++){
    	cin>>k>>l>>r;
    	if(l>r)  swap(l,r);
    	if(!k)  update(1,1,n,l,r);
    	else cout<<ser(1,1,n,l,r)<<endl;
	}
	return 0;
}