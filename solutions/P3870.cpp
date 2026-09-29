#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n,m,ta[N<<2],t[N<<2];

void push_d(int p,int l,int r){
    if(!ta[p])  return;
    int mid=l+r>>1;
    ta[p<<1|1]^=1;ta[p<<1]^=1;
    t[p<<1]=(mid-l+1)-t[p<<1];
    t[p<<1|1]=(r-mid)-t[p<<1|1];
    ta[p]=0;
}
void add(int p,int l,int r,int x,int y){
    if(l>=x&&r<=y){
        t[p]=(r-l+1)-t[p];
        ta[p]^=1;
        return;
    }
    if(l>y||r<x)  return;
    push_d(p,l,r);
    int mid=l+r>>1;
    add(p<<1,l,mid,x,y);add(p<<1|1,mid+1,r,x,y);
    t[p]=t[p<<1]+t[p<<1|1];
}
int ser(int p,int l,int r,int x,int y){
   if(l>=x&&r<=y)  return t[p];
   if(l>y||r<x)  return 0;
   push_d(p,l,r);
   int mid=l+r>>1;
   int ans=0;
   ans=ser(p<<1,l,mid,x,y)+ser(p<<1|1,mid+1,r,x,y);
   return ans;
}
signed main() {
    cin>>n>>m;
    for(int i=1,lx,x,y;i<=m;i++){
        cin>>lx>>x>>y;
        if(lx==0)  add(1,1,n,x,y);
        else cout<<ser(1,1,n,x,y)<<endl;
    }
    return 0;
}