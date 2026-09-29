#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n,m,fa[N],val[N];

struct num{
	int x,y,val;
}a[N];
int find(int x){
	if(fa[x]!=x)  return fa[x]=find(fa[x]);
	else return x;
}
inline bool cmp(num p,num q){
	return p.val>q.val;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)  fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].val;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=a[i].x,y=a[i].y;
		int fx1=find(x),fx2=find(x+n),fy1=find(y),fy2=find(y+n);
//		cout<<fx1<<" "<<fx2<<" "<<fy1<<" "<<fy2<<endl;
		if(find(x)==find(y)||find(x+n)==find(y+n)){
			cout<<a[i].val;
			return 0;
		}
		fa[fx1]=fy2;
		fa[fx2]=fy1;
	}
	cout<<0;
	return 0;
}