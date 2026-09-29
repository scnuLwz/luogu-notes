#include<bits/stdc++.h>

using namespace std;

const int N =  1e6 + 10;
int n,bel[N],s[N],t,step[N],to[N],st[N],ed[N];

int a[N],m;
void update(int l,int r){
	for(int i=r;i>=l;i--){
		if(a[i]+i>ed[bel[i]]){
			step[i]=1;
			to[i]=a[i]+i;
		}
		else{
			step[i]=step[i+a[i]]+1;
			to[i]=to[i+a[i]];
		}
	}
}
void build(){
	for(int i=1;i<=t;i++)
	{
		st[i]=n/t*(i-1)+1;
		ed[i]=n/t*i;
	}
	ed[t]=n;
	for(int i=1;i<=t;i++)
	  for(int j=st[i];j<=ed[i];j++)
	    bel[j]=i;
	update(1,n);
}
int ser(int x){
	int ans=0;
	for(;x<=n;x=to[x])  ans+=step[x];
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	t=sqrt(n);
	for(int i=1;i<=n;i++)  cin>>a[i];
	build();
	cin>>m;
	for(int i=1,opt,x,y;i<=m;++i){
		cin>>opt>>x;
		++x;
		if(opt==1){
			cout<<ser(x)<<endl;
		}
		else{
			cin>>y;
			a[x]=y;
	        update(st[bel[x]],ed[bel[x]]);
		}
	}
	return 0;
}