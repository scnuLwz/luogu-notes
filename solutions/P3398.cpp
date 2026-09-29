#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;

vector<int> v[N];
int n,q,dep[N],f[N][30],lg[N],h[N];

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	h[x]=h[fa]+1;
	for(int i=1;i<=lg[dep[x]];i++)
	  f[x][i]=f[f[x][i-1]][i-1];
	for(int i:v[x]){
		if(i==fa)  continue;
		dfs(i,x);
	}
}
int get_lca(int x,int y){
	if(dep[x]<dep[y])  swap(x,y);
	while(dep[x]>dep[y])  //x处在下面 
	  x=f[x][lg[dep[x]-dep[y]]-1];
	if(x==y)  return x;
    //两侧跳lca
	for(int k=lg[dep[x]]-1;k>=0;k--)
	  if(f[x][k]!=f[y][k]){
	  	x=f[x][k];y=f[y][k];
	  } 
	if(x==y)  return x;
	return f[x][0];
}
int dis(int x,int y){
	return h[x]+h[y]-(h[get_lca(x,y)]<<1);
}
int main(){
	cin>>n>>q;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)//log(i)+1
	  lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(1,0);
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(dis(a,b)+dis(c,d)>=dis(a,c)+dis(b,d))
		  cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}