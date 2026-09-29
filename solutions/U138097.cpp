#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int a[N],n,ans,b[N],cnt,maxn,m;
bool vis[N];

void solve(){
	a[m+1]=1e9+10;
	for(int i=m-1;i>=1;i--){
		if(ans>=a[i])  break;
		for(int j=2;a[i]*(j-1)<=maxn;++j){
			int p=lower_bound(a+1,a+m+2,a[i]*j)-a-1;
			if(a[p]>a[i]&&p!=m+1)  ans=max(ans,a[p]%a[i]);
			if(a[p]%a[i]==a[i]-1)  break;
	//		cout<<i<<" "<<j<<" "<<p<<" "<<a[p]<<" "<<a[i]<<endl;
		}
	}
	cout<<ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];maxn=max(maxn,a[i]);
	} 
	sort(a+1,a+n+1);m=unique(a+1,a+n+1)-a-1;
	if(m<=10000){
	    for(int i=1;i<=m;i++)
	      for(int j=i-1;j>=1;j--){
	  	    ans=max(ans,a[i]%a[j]);
	      }
	    cout<<ans;
	}
	else{
		ans=0;
	    solve();
	}
	
	return 0;
}