#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10 , INF = 1e9 + 10;

int cnt,fa[N],tot,dfn[N],low[N],val[N],n,m,in[N],ans,ansx,a[N];
bool vis[N];
stack<int> sta;
vector<int> v[N],g[N],D,leg;
void tarjan(int x){
	sta.push(x);
	dfn[x]=low[x]=++tot;
	vis[x]=true;
	for(int t:v[x]){
		if(!dfn[t]){
			tarjan(t);
			low[x]=min(low[x],low[t]);
		}
		else if(vis[t]){
			low[x]=min(low[x],dfn[t]);
		}
	}
	if(dfn[x]==low[x]){
		++cnt;
		while(sta.top()!=x){
			int t=sta.top();
			sta.pop();
			fa[t]=cnt;
			val[cnt]=min(val[cnt],a[t]);	
			vis[t]=false;
		}
		val[cnt]=min(val[cnt],a[x]);
		fa[x]=cnt;
		sta.pop();
		vis[x]=false;
	}
}
signed main(){	
    cin>>n>>m;
    for(int i=1;i<=n;i++)  a[i]=val[i]=INF;
    for(int i=1,x,y;i<=m;++i){
    	cin>>x>>y;
    	a[x]=y;
	}
	int Q;cin>>Q;
    for(int i=1,x,y;i<=Q;i++){
    	cin>>x>>y;
    	v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]&&a[i]!=INF)
		  tarjan(i);
	}
	for(int i=1;i<=n;i++)
	  if(!dfn[i]){
	  	return cout<<"NO"<<endl<<i,0;
	  }
	for(int i=1;i<=n;i++)
	  for(int j:v[i]){
	  	int x=fa[i],y=fa[j];
	  	if(x!=y){
	  	//	cout<<x<<" "<<y<<endl;
	  		g[x].push_back(y);++in[y];
		}
	  }
	for(int i=1;i<=cnt;i++)  
	  if(!in[i])
	    ans+=val[i];
	cout<<"YES"<<endl<<ans;
	return 0;
}