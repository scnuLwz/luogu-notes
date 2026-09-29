#include<bits/stdc++.h>

using namespace std;

const int N = 5010;

typedef pair<int,int> PII;
PII b[N];
int d[N],n,m;
bool vis[N];
vector<int> v[N];
int ans[N],cnt,sum[N];
void dfs1(int p,int fa){
	vis[p]=true;cout<<p<<" ";
	for(int t:v[p]){
		if(t==fa||vis[t])  continue;
		dfs1(t,p);
	}
}
bool fl;
void dfs2(int x,int y,int p,int fa){
	if(vis[p])  return;vis[p]=true;
    //cout<<p<<" ";  
	sum[++cnt]=p;
	for(int t:v[p]){
		if(t==fa||(p==y&&x==t)||(p==x&&y==t))  continue;
		//cout<<p<<" "<<t<<endl;
		dfs2(x,y,t,p);
	}
}
bool chk(){
	for(int i=1;i<=n;i++){
		if(ans[i]>sum[i])  return 1;
		if(ans[i]<sum[i])  return 0;
	}
}
signed main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;b[i]={x,y};
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)  sort(v[i].begin(),v[i].end()),ans[i]=N+10;
	if(n!=m)  dfs1(1,0);
	else{
		for(int i=1;i<=m;i++){
			memset(vis,false,sizeof vis);
			cnt=0;
			dfs2(b[i].first,b[i].second,1,0);
		//	puts("");
			if(cnt<n)  continue;
			if(chk()){
				for(int j=1;j<=n;j++)  ans[j]=sum[j];
			}
		}
		for(int i=1;i<=n;++i)  cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 10
5 10
4 1
6 2
1 7
9 2
3 8
7 6
9 4
2 10
2 3
1 4 7 6 2 3 8 9 10 5

*/