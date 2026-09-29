#include <bits/stdc++.h>
//#pragma GCC optimze(3) 
#define int long long
using namespace std;

const int N = 1e6 + 10;

int T,n,m;
vector<int> v[N];
bool e[N];
void add(int x,int y){
	e[x]=e[y]=true;
	v[x].push_back(y);
} 
int cnt,tot,dfn[N],low[N],fa[N];
stack<int> sta;
bool vis[N];
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
int gett(string s){
	int x=0;
	for(int i=1;i<s.size();i++)
	   x=x*10+s[i]-48;
	return x;
}
void solve(){
	cin>>n>>m;tot=cnt=0;
	for(int i=1;i<=4*n;i++)  vis[i]=e[i]=dfn[i]=low[i]=fa[i]=0;
	for(int i=1;i<=4*n;i++)  v[i].clear();
	for(int i=1;i<=m;++i){
		string p,q;
		cin>>p>>q;
		int idp=gett(p),idq=gett(q);
		//cout<<idp<<" "<<idq<<endl;
	    if(p[0]=='m'&&q[0]=='m'){
	    	//!p->q  !q->p
	    	add(idp+n,idq);
	    	add(idq+n,idp);
		}
		if(p[0]=='m'&&q[0]=='h'){
			//!p->q !q->p
			add(idp+n,idq+n);
			add(idq,idp);
		}
		if(p[0]=='h'&&q[0]=='m'){
			add(idp,idq);
			add(idq+n,idp+n);
		}
		if(p[0]=='h'&&q[0]=='h'){
			add(idp,idq+n);
			add(idq,idp+n);
		}
	}
	for(int i=1;i<=2*n;i++)
	  if(!dfn[i])
	    tarjan(i);
//	for(int i=1;i<=2*n;i++)  
//	  if(e[i])
//	    cout<<fa[i]<<' '<<fa[i+2*n]<<endl;
	for(int i=1;i<=n;i++)
	  if(e[i]&&fa[i]==fa[i+n]){
	  	cout<<"BAD"<<endl;
	  	return;
	  }
	cout<<"GOOD"<<endl;
}
signed main(){
	cin>>T;
    for(;T;T--,solve());
    return 0;
}