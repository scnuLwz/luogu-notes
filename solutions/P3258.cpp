#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int n,a[N],f[N][30],dep[N],lg[N],s[N],c[N];
vector<int> v[N];

void dfs(int p,int fa){
	dep[p]=dep[fa]+1;f[p][0]=fa;
	for(int i=1;i<=lg[dep[p]];i++)
	  f[p][i]=f[f[p][i-1]][i-1];
	for(int t:v[p]){
		if(t==fa)  continue;
		dfs(t,p);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])  swap(x,y);
	while(dep[x]>dep[y])
	  x=f[x][lg[dep[x]-dep[y]]-1];
	if(x==y)  return x;
	for(int k=lg[dep[x]]-1;k>=0;k--)
	  if(f[x][k]!=f[y][k])
	    x=f[x][k],y=f[y][k];
	if(x==y)  return x;
	return f[x][0];
}
void ser(int p,int fa){
	int ans=0;
	for(int t:v[p]){
		if(t!=fa){
			ser(t,p);
			s[p]+=s[t];
		}
	}
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)  lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<n;i++){
		int d1=a[i],d2=a[i+1];
		int t=lca(d1,d2);
		s[d1]++;s[d2]++;
		s[t]--;s[f[t][0]]--;
	}
	ser(1,0);
	for(int i=2;i<=n;i++)  s[a[i]]--;//终点被减多一次 
	for(int i=1;i<=n;i++){
		cout<<s[i]<<endl;
	}
	  
	return 0;
}