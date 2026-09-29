#include<bits/stdc++.h>
#define ls(p) p<<1 
#define rs(p) p<<1|1
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;

int t[N<<2],n,m,a[N],ta[N<<2];

void build(int p,int l,int r){
    if(l==r){
        t[p]=a[l];return;
    }  
    if(l>r)  return;
    int mid=(l+r)>>1;
    build(ls(p),l,mid);build(rs(p),mid+1,r);
    t[p]=t[ls(p)]+t[rs(p)];
}
void push_d(int p,int l,int r){
    if(ta[p]==0)  return;
    int mid=(l+r)>>1;
    ta[ls(p)]^=1;ta[rs(p)]^=1;
    t[ls(p)]=(mid-l+1)-t[ls(p)];
    t[rs(p)]=(r-mid)-t[rs(p)];
    ta[p]=0;
    return;
}
void add(int p,int l,int r,int x,int y){
    push_d(p,l,r);
    if(l>=x&&r<=y){
        t[p]=(r-l+1)-t[p];
        ta[p]^=1;
        return;
    }
    if(l>y||r<x)  return;
    int mid=(l+r)>>1;
    add(ls(p),l,mid,x,y);add(rs(p),mid+1,r,x,y);
    t[p]=t[ls(p)]+t[rs(p)];
}
int ser(int p,int l,int r,int x,int y){
    if(l>=x&&r<=y){
        return t[p];
    }
    if(l>y||r<x)  return 0;
    push_d(p,l,r);
    int mid=(l+r)>>1;
    int ans=0;
    ans+=ser(ls(p),l,mid,x,y);
    ans+=ser(rs(p),mid+1,r,x,y);
    return ans;
}
signed main(){
	cin>>n>>m;
	for(int i=1,opt,x,y;i<=m;i++){
	    cin>>opt>>x>>y;
	    if(opt==0){
	        add(1,1,n,x,y);
	    }
	    else{
	        cout<<ser(1,1,n,x,y)<<endl;
	    }
	}
	return 0;
}

