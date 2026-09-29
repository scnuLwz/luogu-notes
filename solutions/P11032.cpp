#include<bits/stdc++.h>
#define int __int128
using namespace std;

const int N = 1e6 + 10;

int n,k,fac[110][110],inv[110][110],f[N][2],g[N],tot,mod[N];
map<int,int> id,sum;
vector<int> v[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}

int fpow(int a,int b,int mod){
	int res=1;
	while(b){
		if(b&1)  res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
void dfs(int p,int fa){
	for(int t:v[p]){
		if(t==fa)  continue;	
		dfs(t,p);	
		f[p][1]+=f[t][0];
		f[p][0]+=f[t][1];
	}
} 
int C(int x,int y,int mod){
	if(y>x)  return 0;
	if(x==y)  return 1;
	if(y==1)  return x;
	int cnt=1,ans;
	for(int i=x-y+1;i<=x;i++)  cnt=cnt*i%mod;
	ans=cnt*inv[id[mod]][y]%mod;
	return ans;
}
void print(int x){
	if(x>9)  print(x/10);  
	putchar(x%10+'0');
}
void solve(){
	for(int i=1;i<=tot;i++){
		int now=sum[i];//cout<<i<<" "<<now<<endl;
		inv[i][0]=fac[i][0]=1;
		for(int j=1;j<=20;j++){
			fac[i][j]=fac[i][j-1]*j%now;
			inv[i][j]=fpow(fac[i][j],now-2,now);
		}
	}
	for(int i=1;i<=n;i++)  print(C(g[i],k,mod[i])%mod[i]),cout<<" ";
}
signed main(){
	n=read();k=read();
	for(int i=1,x,y;i<n;i++){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
    for(int i=1;i<=n;i++)  f[i][0]=1;
	dfs(1,0);
	for(int i=1;i<=n;i++)  g[i]=f[i][0]*f[i][1];
	for(int i=1;i<=n;i++){
		mod[i]=read();
		if(!id[mod[i]]){
			id[mod[i]]=++tot;sum[tot]=mod[i];
		}  
	}  
	solve();
	return 0;
}