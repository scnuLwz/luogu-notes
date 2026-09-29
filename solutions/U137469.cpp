#include<bits/stdc++.h>
#define int long long 
using namespace std;

int T,n,m,k,sum;
map<int,int> vis; 

int ksm(int a,int b,int mod){
	int res=1;
	while(b){
		if(b&1)  res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
void solve(){
	//cout<<ksm(2,3,100);
	cin>>n>>m>>k;sum=n+m;
	if(k<=1e6){
	    for(int i=1;i<=k;i++){
		    if(n>m){
			    n-=m;
			    m=2*m;
		    }
	    	else{
			    m-=n;
			    n=2*n;
	    	}    
	     	//cout<<n<<" "<<m<<endl;
	    //	if(!n||!m)  break;
	    }
    	cout<<min(n,m)<<endl;
	}
	else{
		int mod=n+m;
		cout<<min(n*ksm(2,k,mod)%mod,m*ksm(2,k,mod)%mod)<<endl;
	}
}
signed main(){
	cin>>T;
	while(T--)  solve();
	return 0;
}