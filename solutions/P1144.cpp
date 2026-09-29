#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10 , mod = 100003;

int an[N],n,m,dis[N];

queue<int> q;
bool vis[N];
vector<int> v[N];

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main(){
	memset(dis,0x3f,sizeof dis);
	n=read();m=read();
	for(int i=1,x,y;i<=m;i++){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(1);vis[1]=true;an[1]=1;dis[1]=0;
	while(q.size()){
		int t=q.front();
		q.pop();
		vis[t]=false;
		for(int p:v[t]){
			if(dis[p]>dis[t]+1){
				dis[p]=dis[t]+1;
				an[p]=an[t];
				if(!vis[p]){
					vis[p]=true;
					q.push(p);
				}
			}
			else if(dis[p]==dis[t]+1){
				an[p]+=an[t];
				an[p]%=mod;
				
			}
		}
	}
	for(int i=1;i<=n;i++)  cout<<an[i]<<endl;
	return 0;
}