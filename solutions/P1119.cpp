#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 210 , mod = 100003;

int n,m,t[N],f[N][N];

struct node{
	int y,val;
};
vector<node> v[N]; 
bool vis[N];bool g[N][N];
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
void gx(int p){
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++){
	  	f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
	  }
}
signed main(){
	memset(f,0x3f,sizeof f);
	n=read();m=read();
	for(int i=0;i<n;i++)  t[i]=read();
	for(int i=0,x,y,z;i<m;i++){
		x=read();y=read();z=read();
//		v[x].push_back({y,z});
//		v[y].push_back({x,z});
        f[x][y]=f[y][x]=z;
	}
	int Q,lat=0,j=0;
	Q=read();
	while(Q--){
		int x,y,T;
		x=read();y=read();T=read();
		while(t[j]<=T&&j<=n){
			gx(j);
			++j;
		}
		//cout<<j<<" ";
		if(t[x]>T||t[y]>T||f[x][y]>1e8)  cout<<-1<<endl;
		else cout<<f[x][y]<<endl;
	}
	return 0;
}