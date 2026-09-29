#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;

int n,m,k,ans,cnt[N],last[N],now,sum[N];
signed main(){
	ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1,c,w;i<=n;i++){
    	cin>>c>>w;
    	if(w<=k)  now=i;
    	if(now>=last[c])  sum[c]=cnt[c];
    	ans+=sum[c];
    	last[c]=i;
    	++cnt[c];
	}
	cout<<ans;
    return 0;
}