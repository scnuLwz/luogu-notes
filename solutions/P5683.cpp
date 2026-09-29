#include<bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;

int dis[N][N],n,m,ed1,ed2,t1,t2,f[N],ans=1e9;
pair<int,int> p[N];
vector<int> v[N];

void bfs(int p){
	memset(f,0x3f,sizeof f);
	queue<int> q;q.push(p);f[p]=0;
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i:v[t]){
			if(f[i]>f[t]+1){
				f[i]=f[t]+1;
				q.push(i);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		if(x==y)  continue;
		v[x].push_back(y);
		v[y].push_back(x);
		p[i]={x,y}; 
	}cin>>ed1>>t1>>ed2>>t2;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=1;j<=n;j++)  dis[i][j]=f[j];
	}
	if(dis[1][ed1]>t1||dis[1][ed2]>t2)  cout<<-1;
	else if(ed1==ed2)  cout<<m-dis[1][ed1];
	else{
		if(dis[1][ed2]+dis[ed2][ed1]==dis[1][ed1]||dis[1][ed1]+dis[ed1][ed2]==dis[1][ed2]){
			//在最短路上
			cout<<m-max(dis[1][ed1],dis[1][ed2]); 
		}
		else{
			for(int i=2;i<=n;i++){
				if(dis[1][i]+dis[i][ed1]==dis[1][ed1]&&dis[1][i]+dis[i][ed2]==dis[1][ed2])
				  ans=min(ans,dis[i][ed2]);
			}
			if(ans<1e8){
				ans+=dis[1][ed1];
			    cout<<m-ans;
			}
			else{
				cout<<m-(dis[1][ed1]+dis[1][ed2]);
			}
		}
	}
	return 0;
}