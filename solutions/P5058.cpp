#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;
const int N = 1e6 + 10;

PII d[N];
vector<int> v[N];
int n,bx,ex,m,dfn[N],low[N],tot;
bool vis[N];
void tarjan(int p){
	dfn[p]=low[p]=++tot;
	for(int t:v[p]){
		if(!dfn[t]){
			tarjan(t);
			low[p]=min(low[p],low[t]);
			if(low[t]>=dfn[p]&&p!=bx&&dfn[ex]>=dfn[t])
			  vis[p]=true;  
		}
		else low[p]=min(low[p],dfn[t]);
	}
}
int main(){
	cin>>n;
	for(int i=1,x,y;;i++){
		cin>>x>>y;
		if(!x&&!y)  break;
		v[x].push_back(y);
		v[y].push_back(x);
		d[++m]={x,y};
	}
	cin>>bx>>ex;
	tarjan(bx);
	for(int i=1;i<=n;i++){
		if(vis[i])
		  return cout<<i,0;
	}
	cout<<"No solution";
	return 0;
}