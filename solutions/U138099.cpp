#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int n,a[N],ans,q[N],h[N];
bool vis[N];

void solve(){
	int j=n/2+1;
	for(int i=1;i<=n/2;i++){
		while(a[j]<a[i]*2&&j<=n)  j++;
		if(j>n)  break;
		if(a[j]>=a[i]*2){
			vis[i]=vis[j]=true;
			ans++;
			++j;
		}
	}
	for(int i=1;i<=n;i++)
	  if(!vis[i])
	    ans++;
	cout<<ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	solve();
	return 0;
}