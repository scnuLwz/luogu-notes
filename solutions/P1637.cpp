#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,a[N],ans,c[N],s[N],b[N];

void add(int x,int y){
	for(;x<N;x+=x&-x)
	  c[x]+=y;
}
int ser(int x){
	int ans=0;
	for(;x;x&=x-1)
	  ans+=c[x];
	return ans;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		s[i]+=ser(a[i]);
		add(a[i]+1,1);
	}
	memset(c,0,sizeof c);
	for(int i=n;i>=1;i--){
		b[i]+=ser(N-1)-ser(a[i]);
		add(a[i],1);
	}
	for(int i=1;i<=n;i++)  ans+=s[i]*b[i];
	cout<<ans;
	return 0;
} 