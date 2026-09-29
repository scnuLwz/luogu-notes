#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 10;
int n,m,a[N],b[N];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	while(m--){
		int opt,l,r;
		cin>>opt>>l;
		if(opt==1){
			cin>>r;
			b[l]+=r;  //a[r*k]+=l
		} 
		else{
			//a[l]
			int ans=0;
			for(int i=1;i*i<=l;i++){
			    if(l%i==0){
			    	ans+=b[i];
			    	if(i*i!=l)  ans+=b[l/i];
				}
			}
			cout<<a[l]+ans<<endl;
		}
	}
	return 0;
}