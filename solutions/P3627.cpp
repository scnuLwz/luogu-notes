#include<bits/stdc++.h> 

using namespace std;

const int N = 1e6 + 10;
int n,m,val[N],vv[N],bar[N],dfn[N],low[N],tot,cnt,fa[N],st;
int k,a[N],beg;
bool vis[N];
stack<int> sta;
vector<int> v[N],g[N];
void tarjan(int x){
	sta.push(x);vis[x]=true;dfn[x]=low[x]=++tot;
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
			if(t==st)  beg=cnt;
			fa[t]=cnt;
			vis[t]=false;
			bar[cnt]=max(bar[cnt],vv[t]);
			val[cnt]+=a[t];
			sta.pop();
		}
		if(x==st)  beg=cnt;
		fa[x]=cnt;
		val[cnt]+=a[x];
		bar[cnt]=max(bar[cnt],vv[x]);
		vis[x]=false;
		sta.pop();
	}
}
int dis[N];
void spfa(){
	memset(vis,false,sizeof vis);
	dis[beg]=0;queue<int> q;
	q.push(beg);
	vis[beg]=true;
	for(int i=1;i<=cnt;i++)  dis[i]=-val[i];
	while(q.size()){
		int t=q.front();q.pop();
		vis[t]=false;
		for(int p:g[t]){
			if(dis[p]>dis[t]-val[p]){
				dis[p]=dis[t]-val[p];
				if(!vis[p]){
					vis[p]=true;
					q.push(p);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++)
	  if(bar[i])
	    ans=min(ans,dis[i]);
	cout<<-ans;
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)  cin>>a[i];
	cin>>st>>k;
	for(int i=1,x;i<=k;i++){
		cin>>x;
		vv[x]=1;
	}
	for(int i=1;i<=n;i++)
	  if(!dfn[i])
	    tarjan(i);
	for(int i=1;i<=n;i++)
	  for(int j:v[i]){
	  	int x=fa[i],y=fa[j];
	  	if(x!=y){
	  		//cout<<x<<' '<<y<<endl;
	  		g[x].push_back(y);
		  }
	  }
//	cout<<beg;
//	for(int i=1;i<=cnt;i++)  cout<<val[i]<<" "<<bar[i]<<endl; 
//	for(int i=1;i<=cnt;i++,cout<<endl)
//	  for(int j:g[i])
//	    cout<<j<<" ";
    spfa();
	return 0;
}