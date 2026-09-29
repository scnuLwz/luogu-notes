#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n,m,f[N][20],g[N][20],Q,dep[N];

struct node{
	int x,y,val;
}e[N];
struct num{
	int d,w;
};
int fa[N];
int find(int x){
	if(fa[x]!=x)  return fa[x]=find(fa[x]);
	else return x;
}
vector<num> v[N];
void dfs(int p,int fa){
	f[p][0]=fa;dep[p]=dep[fa]+1;
	for(num t:v[p]){
		if(t.d==fa)  continue;
		g[t.d][0]=t.w;
		dfs(t.d,p);
	}
}
void ksl(){
	int tot=0;
	for(int i=1;i<=n;i++)  fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx==fy)  continue;
		fa[fx]=fy;
		v[e[i].x].push_back({e[i].y,e[i].val});
		v[e[i].y].push_back({e[i].x,e[i].val});
		if(++tot==n-1)  break;
	}
	for(int i=1;i<=n;i++)  fa[i]=find(i);
	for(int i=1;i<=n;i++)
	  if(fa[i]==i)  
	    dfs(i,0);
}
void solve(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
		    f[i][j]=f[f[i][j-1]][j-1];
		    g[i][j]=max(g[f[i][j-1]][j-1],g[i][j-1]);
	    }
    }
}
int query(int x,int y){
	if(dep[x]<dep[y])  swap(x,y);
	int ans=0,d=dep[x]-dep[y];
	for(int i=19;i>=0;i--){
		if(d&(1<<i)){
			ans=max(ans,g[x][i]);x=f[x][i];
		}
	}
	if(x==y)  return ans;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			ans=max(ans,max(g[x][i],g[y][i]));
			x=f[x][i],y=f[y][i];
		}
	}
	ans=max(ans,max(g[x][0],g[y][0]));
	return ans;
}
inline bool cmp(node p,node q){
	return p.val<q.val;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].val;
	}
	sort(e+1,e+m+1,cmp);
	ksl();
	solve();cin>>Q;
	for(int i=1,x,y;i<=Q;i++){
		cin>>x>>y;
		if(fa[x]!=fa[y])  cout<<"impossible"<<endl;
		else cout<<query(x,y)<<endl; 
	}
	return 0;
}