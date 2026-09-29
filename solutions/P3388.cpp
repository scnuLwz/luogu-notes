#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int n,m,dfn[N],low[N],tot,fx[N],sta,ans;
vector<int> v[N];

void tarjan(int p){
	dfn[p]=low[p]=++tot;
	int sum=0;
	for(int t:v[p]){
		if(!dfn[t]){
			sum++;
			tarjan(t);
			low[p]=min(low[p],low[t]);
			if(low[t]>=dfn[p]&&p!=sta){
				ans+=!fx[p];fx[p]=1;
			}
		}else low[p]=min(low[p],dfn[t]);
	}
	if(sum>=2&&p==sta){
		ans+=!fx[p];fx[p]=1;
	}
}
signed main(){
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++){
    	cin>>x>>y;
    	v[x].push_back(y);v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	  if(!dfn[i]){
	  	sta=i;tarjan(i);
	  }
	    
	cout<<ans<<endl;
	for(int i=1;i<=n;++i)  if(fx[i])  cout<<i<<" ";
	return 0;
}