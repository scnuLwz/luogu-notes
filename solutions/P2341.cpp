#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 50010;

int dfn[N],low[N],tot,fa[N],n,m,in[N],f[N],val[N],ds,cnt,ff[N];
bool vis[N];
vector<int> v[N],g[N]; 
void add(int x,int y,int lx){
	if(!lx){
		v[x].push_back(y);
	}
	else{
		g[x].push_back(y);in[y]++;
	}
}
void dfs(int k){
	//cout<<k<<" ";
	f[k]++;ff[k]=1;
	for(int t:g[k]){
		if(!ff[t])
		  dfs(t);
	}
}
void bfs(){
	for(int i=1;i<=cnt;++i){
		dfs(i);
		for(int j=1;j<=cnt;j++)  ff[j]=0;
	}
	int ans=0;
	for(int i=1;i<=cnt;++i)	  
	  if(f[i]==cnt)
	    ans+=val[i];
	cout<<ans;
}
stack<int> sta;
void tarjan(int x){
	sta.push(x);
	dfn[x]=low[x]=++tot;
	vis[x]=true;
	for(int p:v[x]){
		if(!dfn[p]){
			tarjan(p);
			low[x]=min(low[p],low[x]);
		}
		else if(vis[p]){
			low[x]=min(dfn[p],low[x]);
		}
	}
	if(dfn[x]==low[x]){
		++cnt;
		while(sta.top()!=x){
			int t=sta.top();sta.pop(); 
			val[cnt]++;
			fa[t]=cnt;
		    vis[t]=false;
	    }
	    fa[x]=cnt;
	    sta.pop();
	    vis[x]=false;
	}
	
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)  val[i]=1;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		add(x,y,0);
	}
	for(int i=1;i<=n;i++)
	  if(!dfn[i])
	    tarjan(i);
    for(int i=1;i<=n;i++)
      for(int to:v[i]){
      	int x=fa[i],y=fa[to];
      	if(x!=y){
      	//	cout<<x<<" "<<y<<endl;
      		add(x,y,1);
		}
	  } 
	bfs();
	return 0;
}