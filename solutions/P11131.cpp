#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10 , INF = 1e18;

map<int,map<int,int> > a;
typedef pair<int,int> PII;
int n,m,q,f[4][2]={{1,0},{0,1},{-1,0},{0,-1}},dis[51][N],maxn,val[N],ans=INF,cnt[N];
int cal(int x,int y){
	return (x-1)*m+y;
}

vector<int> v[N];bool vis[N];
void dij(int k,int x,int y){
	for(int i=1;i<=maxn;i++){
		dis[k][i]=INF;
		vis[i]=false;
	}  
	dis[k][cal(x,y)]=a[x][y];
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({a[x][y],cal(x,y)});
	while(q.size()){
		int t=q.top().second;
		q.pop();
		if(vis[t])  continue;
		vis[t]=true;
		for(int p:v[t]){
			if(dis[k][p]>dis[k][t]+val[p]){
				dis[k][p]=dis[k][t]+val[p];
				q.push({dis[k][p],p});
			}
		}
	}
}
signed main(){
	cin>>n>>m>>q;maxn=n*m;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++){
	  	cin>>a[i][j];val[cal(i,j)]=a[i][j];
	  	for(int k=0;k<4;k++){
	  		int xx=f[k][0]+i,yy=f[k][1]+j;
	  		if(xx<1||yy<1||xx>n||yy>m)  continue;
	  		v[cal(i,j)].push_back(cal(xx,yy));
		}
	  }
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++){
	  	for(int k=0;k<4;k++){
	  		int xx=f[k][0]+i,yy=f[k][1]+j;
	  		if(xx<1||yy<1||xx>n||yy>m)  continue;
	  		if(val[cal(xx,yy)]<-val[cal(i,j)]&&val[cal(i,j)]<0){
	  			return cout<<"No",0;
			}
		}
	  }
	//maxn+=n;
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		dij(i,x,y);
	}
    for(int i=1;i<=maxn;i++){
    	int sum=-INF;
    	for(int j=1;j<=q;j++)  sum=max(sum,dis[j][i]);
    	ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}