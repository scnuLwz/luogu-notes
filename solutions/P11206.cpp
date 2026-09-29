#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int dep[N],n,d[N],ans[N],mi,mx;
vector<int> v[N];
bool vis[N];
void dfs(int p,int fa){
	for(int t:v[p]){
		if(t==fa)  continue;
		dfs(t,p);
	}
	if(!ans[p]){
		ans[p]=mx;mx--;
		if(!ans[fa]&&fa)  ans[fa]=mi++;
	}  
} 
void solve(){
	memset(vis,false,sizeof vis);memset(ans,0,sizeof ans);
	cin>>n;mi=1;mx=n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0); 
	for(int i=1;i<=n;i++)  v[i].clear();
	for(int i=1;i<=n;i++)  cout<<ans[i]<<" ";
	cout<<endl;
} 
int main(){
	int T;cin>>T;
	while(T--)  solve();
	return 0;
}