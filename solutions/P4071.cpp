#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7 , N = 1e6 + 10;
int T,f[N],n,m,fac[N],inv[N];

int poww(int a,int b){
	int res=1;
	while(b){
		if(b&1)  res=(res*a)%mod;
		a=(a*a)%mod;b>>=1;
	}
	return res;
}
int invv(int x){
	return poww(x,mod-2);
}
void solve(){
	if(n==m){
		cout<<1;return;
	}
	int d=f[n-m];
	if(!m){
		cout<<d;return;
	}
	if(n-m==1){
		cout<<0;return;
	}
	int res=fac[n]*inv[m]%mod*inv[n-m]%mod*d%mod;
	cout<<res;
}
signed main(){
	f[2]=1;f[3]=2;
	for(int i=4;i<=N;i++)  f[i]=(i-1)*(f[i-1]+f[i-2])%mod;
	fac[0]=1;
	for(int i=1;i<=N;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=invv(fac[i]);
	}  
	cin>>T;
	while(T--){
		cin>>n>>m;
		solve();puts("");
	}
	return 0;
}