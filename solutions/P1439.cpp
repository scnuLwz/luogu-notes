#include<bits/stdc++.h>
#define rep(i,x,y)  for(int i=x;i<=y;i++)
using namespace std;

const int N = 1e6 + 10 ;

int n,a[N],pos[N],f[N],maxn[N],ans;

void add(int x,int y){
	for(;x<=n;x+=x&-x)  maxn[x]=max(maxn[x],y);
}

int ser(int x){
	int ans=0;
	for(;x;x-=x&-x)  ans=max(ans,maxn[x]);
	return ans;
}
int main()
{
    cin>>n;
	rep(i,1,n)  cin>>a[i];
	rep(i,1,n){
		int x;
		cin>>x;
		pos[x]=i;
	}
	rep(i,1,n){
		int p=pos[a[i]];
		f[p]=ser(p)+1;
		add(p,f[p]);
		ans=max(ans,f[i]);
	}
	return cout<<ser(n),0;
}