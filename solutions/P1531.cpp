#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n,m,a[N],t[N<<2];
void build(int p,int l,int r){
	if(l==r){
		t[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	t[p]=max(t[p<<1],t[p<<1|1]); 
}
int ser(int p,int x,int y,int l,int r){
	if(l>=x&&r<=y){
		return t[p];
	}
	if(l>y||r<x)  return 0;
	int mid=l+r>>1;
	return max(ser(p<<1,x,y,l,mid),ser(p<<1|1,x,y,mid+1,r));
}
void update(int p,int l,int r,int x,int y){
	if(l==r){
		if(t[p]<y)  t[p]=y;
		return;
	}
	//if(r<x||l>y)  return;
	int mid=(l+r)>>1;
	if(x<=mid)  update(p<<1,l,mid,x,y);
	else update(p<<1|1,mid+1,r,x,y);
	t[p]=max(t[p<<1],t[p<<1|1]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	build(1,1,n);
	//cout<<qu(1,1,n,2);
	for(int i=1,l,r;i<=m;i++){
		char opt;
		cin>>opt>>l>>r;
		if(opt=='Q'){
			cout<<ser(1,l,r,1,n)<<endl;
		}
		else{
			update(1,1,n,l,r);
		}
	}
	return 0;
}