#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10 , mod = 1e9 + 7;
map<int,int> X;
int c[N],d[N],n,m,v,a[N];

inline int fpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)  res=(res*a)%mod;
		a=(a*a)%mod;
	    b>>=1;
	}
	return res;
}

void solve(){
	X.clear();
	cin>>n>>m>>v;int cnt=0,ans=fpow(v,2*n-2);bool fl=true;
	for(int i=1;i<=m;i++){
		cin>>c[i]>>d[i];
		if(!X[c[i]])  ++cnt;
		if(X[c[i]]&&d[i]!=X[c[i]]){
			fl=false;
		}  
		X[c[i]]=d[i];
	}
	if(!fl){
		cout<<0<<endl;return;
	}
	ans=1;
    sort(c+1,c+m+1);
    for(int i=2;i<=m;i++){
    	if(c[i]==c[i-1])  continue;
        ans=(ans*(fpow(v,2*(c[i]-c[i-1]))-(fpow(v,c[i]-c[i-1]-1)*(v-1)%mod)+mod))%mod;
	}
	ans=(ans*fpow(v,2*(c[1]-1)))%mod;
	ans=(ans*fpow(v,2*(n-c[m])))%mod;
	cout<<ans<<endl;
}
signed main(){                                 
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)  solve();
	return 0;
}