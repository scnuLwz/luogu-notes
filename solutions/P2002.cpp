#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int cnt,fa[N],tot,dfn[N],low[N],val[N],n,m,in[N],ans,bh[N];
bool vis[N],vv[N];
stack<int> sta;
vector<int> v[N],g[N],D;
map<int,int> mp;
struct node{
	int x,y;
}d[N];
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
			bh[t]=cnt;
			vis[t]=false;
		}
		bh[x]=cnt;
		fa[x]=x;
		sta.pop();
		vis[x]=false;
	}
}
signed main(){	
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++){
    	cin>>x>>y;d[i]={x,y};
    	v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])
		  tarjan(i);
	}
//	for(int i=1;i<=n;i++)  cout<<bh[i]<<" ";
    memset(vv,false,sizeof vv);
	for(int i=1;i<=n;i++)
	  for(int j:v[i]){
	//  	cout<<i<<" "<<j<<" "<<bh[j]<<endl;
	  	if(bh[i]!=bh[j]){
	  	//	cout<<bh[j]<<"ccf";
	  		vv[bh[j]]=true;
		}
	  }
	for(int i=1;i<=cnt;i++)
	  if(!vv[i])
	    ++ans;
	cout<<ans;
	return 0;
}