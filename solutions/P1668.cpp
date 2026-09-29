#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n,m,st,ans,cnt,dis[N];
struct node{
	int x,y;
};
node a[N],b[N];

vector<int> v[N];
inline bool cmp(node a,node b){
	if(a.x!=b.x)  return a.x<b.x;
	else return a.y<b.y;
}
int f[N];

int tr[N<<2];

void up(int p){
	tr[p]=min(tr[p<<1],tr[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r){
	//	cout<<f[l]<<" "<<l<<endl;
		tr[p]=f[l];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);up(p);
}
void update(int p,int l,int r,int x,int y,int k){
	if(x<=l&&y>=r){
		tr[p]=k;
		return;
	}
	if(r<x||l>y)  return;
	int mid=l+r>>1;
	update(p<<1,l,mid,x,y,k);update(p<<1|1,mid+1,r,x,y,k);up(p);
}
int ser(int p,int l,int r,int x,int y){
	if(x<=l&&y>=r)  return tr[p];
	if(r<x||l>y)  return 0x3f3f3f3f;
	int mid=l+r>>1;
	return min(ser(p<<1,l,mid,x,y),ser(p<<1|1,mid+1,r,x,y));
}
int main(){
    memset(f,0x3f,sizeof f);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x==1)  f[a[i].y]=1;
	}  
	sort(a+1,a+n+1,cmp);
	build(1,1,m);
	//cout<<ser(1,1,m,5,9);
	for(int i=1;i<=n;i++){
		//for(int j=a[i].x-1;j<a[i].y;j++)
	    //f[a[i].y]=min(f[a[i].y],f[j]+1);
	    int minn=f[a[i].y];
	    if(ser(1,1,m,a[i].x-1,a[i].y-1)+1<minn){
	    	f[a[i].y]=ser(1,1,m,a[i].x-1,a[i].y-1)+1;
	    	update(1,1,m,a[i].y,a[i].y,f[a[i].y]);
		}
	    //cout<<a[i].x-1<<" "<<a[i].y-1<<" "<<ser(1,1,m,a[i].x-1,a[i].y-1)<<endl;
	    
	}
	if(f[m]>1e9)  cout<<-1;
	else cout<<f[m];
	return 0;
}