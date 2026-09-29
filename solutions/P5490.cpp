#include<bits/stdc++.h>
#define int long long
#define lson (p<<1)
#define rson (p<<1|1)
using namespace std;

const int N = 2e6 + 10;

int n,X[N];
struct node{
	int l,r,h;
	int w;
	bool operator< (const node &other) const{
		return h<other.h;
	}
}line[N<<2]; 
struct stree{
	int l,r,sum,len;
}t[N];
void build(int p,int l,int r){
	t[p].l=l;t[p].r=r;t[p].len=t[p].sum=0;
	if(l==r)  return;
	int mid=l+r>>1;
	build(lson,l,mid);build(rson,mid+1,r);
	return;
} 
void up(int p){
	if(!t[p].sum){
		t[p].len=t[lson].len+t[rson].len;
	}else{
		t[p].len=X[t[p].r+1]-X[t[p].l];
	}
}
void stree_push(int p,int L,int R,int c){
	//覆盖线段[L,R]
	int l=t[p].l,r=t[p].r;
	if(X[r+1]<=L||X[l]>=R)  return;
	if(L<=X[l]&&R>=X[r+1]){
		t[p].sum+=c;
		up(p);
		return;
	}
	stree_push(lson,L,R,c);stree_push(rson,L,R,c);
	up(p);
}
void print(__int128 p){
	if(p>9)  print(p/10);
	putchar(p%10+'0');
}
signed main()
{
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
    for(int i=1,st,ed,stx,sty;i<=n;i++){
    	cin>>st>>ed>>stx>>sty;
    	X[2*i-1]=st;X[2*i]=stx;
    	line[2*i-1]={st,stx,ed,1};
    	line[2*i]={st,stx,sty,-1};
	}
	n<<=1;
	sort(line+1,line+n+1);sort(X+1,X+n+1);
	int tot=unique(X+1,X+n+1)-X-1;
	build(1,1,tot-1);
    __int128 ans=0;
	for(int i=1;i<n;i++){
		stree_push(1,line[i].l,line[i].r,line[i].w);
		//总面积乘以高度差 
		ans+=t[1].len*(line[i+1].h-line[i].h);
	}
	print(ans);
	return 0;
}