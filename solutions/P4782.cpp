#include <bits/stdc++.h>
//#pragma GCC optimze(3) 
#define int long long
using namespace std;

const int N = 2e6 + 10;

int n,m,dfn[N],low[N],cnt,tot,fa[N];
bool vis[N];
vector<int> g[N],v[N];
bool e[N];
void add(int x,int y){
	v[x].push_back(y);
	e[x]=e[y]=true;
}
stack<int> sta;
void tarjan(int x){
	sta.push(x);vis[x]=true;dfn[x]=low[x]=++tot;
	for(int t:v[x]){
		if(!dfn[t]){
			tarjan(t);
			low[x]=min(low[x],low[t]); 
		}
		else if(vis[t]){
			low[x]=min(low[x],low[t]);
		}
	}
	if(dfn[x]==low[x]){
		++cnt;
		while(sta.top()!=x){
			int t=sta.top();
			sta.pop();
			vis[t]=false;
			fa[t]=cnt;
		}
		vis[x]=false;
		fa[x]=cnt;
		sta.pop();
	}
}
signed main() {
    cin>>n>>m;
    for(int i=1,p,q,x,y;i<=m;i++){
    	cin>>p>>x>>q>>y;
    	if(!x&&!y){
    		//p=0/q=0;  p=1->q=0 q=1->p=0
    		add(p+n,q);add(q+n,p);
		}
		if(x&&!y){
			//p=1/q=0;  p=0->q=0  q=1->p=1
			add(p,q);add(q+n,p+n);
		}
		if(!x&&y){
			//p=0/q=1;  p=1->q=1  q=0->p=0
			add(p+n,q+n);add(q,p);
		}
		if(x&&y){
			//p=1/q=1;  p=0->q=1  q=0->p=1
			add(p,q+n);add(q,p+n);
		}
	}
	for(int i=1;i<=2*n;i++)
	  if(!dfn[i])
	    tarjan(i);
	for(int i=1;i<=n;i++){
		if(e[i]&&fa[i]==fa[i+n]){
			return cout<<"IMPOSSIBLE",0;
		}
	}
	cout<<"POSSIBLE"<<endl;
	for(int i=1;i<=n;i++){
		if(fa[i]>fa[i+n])  cout<<"1 ";//叶子节点中true更优 
		else cout<<"0 ";
	}
    return 0;
}