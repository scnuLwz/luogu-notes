#include<bits/stdc++.h>
#define int long long
using namespace std;

const int  N = 1e6 + 10;
typedef pair<int,int> PI;
PI d[N];
int in[N],fa[N],dfn[N],low[N],n,m,a[N],tot,f[N],ans,val[N],sum=1e9;

bool vis[N],p[N];
vector<int> v[N],g[N];
stack<int> sta;queue<int> q;
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
		while(sta.top()!=x){
			int t=sta.top();
			sta.pop();
			fa[t]=x;
			val[x]++;
			vis[t]=false;
		}
		fa[x]=x;
		sta.pop();
		vis[x]=false;
	}
}
signed main(){
	cin>>n>>m;
	for(int i=1,x,y,lx;i<=m;i++){
		cin>>x>>y>>lx;
		d[i]={x,y};
		v[x].push_back(y);
		if(lx==2)  v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)  val[i]=1;
	for(int i=1;i<=n;i++)
	  if(!dfn[i])
	    tarjan(i);
	for(int i=1;i<=n;i++)
	  ans=max(ans,val[i]);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(val[i]==ans){
			for(int j=1;j<=n;j++)
			  if(fa[j]==fa[i])
			    sum=min(sum,j);
		}
	}
//	cout<<val[2];
//	cout<<sum;
	for(int i=1;i<=n;i++){
		if(sum==i){
			//cout<<"Ak";
			for(int j=1;j<=n;j++)
			  if(fa[j]==fa[i])
			    cout<<j<<" ";
		}
	}
	return 0;
} 