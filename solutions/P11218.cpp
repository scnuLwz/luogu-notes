#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

int f[N][3],g[N],n,m,a[2][N];
void solve(){
	memset(f,0,sizeof f);memset(g,0,sizeof g);
	cin>>n>>m;
	for(int i=0;i<=1;i++)
	  for(int j=1;j<=n;j++){
	  	char c;cin>>c;
	  	a[i][j]=c-48;
	  }
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[0][i]==a[1][i]){
			if(!a[0][i])  g[i]=max(-1,g[i-1]-1);
			else g[i]=max(2,g[i-1]+2);
		}
		else g[i]=max(g[i],g[i-1]); 
		ans=max(ans,g[i]);
	}
	for(int i=0;i<=1;i++)
	  for(int j=1;j<=n;j++){
	  	if(!a[i][j])  a[i][j]=-1;
	  }
	int sum=0;
	for(int i=1;i<=n;i++){
		f[i][0]=max(a[0][i]+a[1][i],max(f[i-1][0],max(f[i-1][1],f[i-1][2]))+a[0][i]+a[1][i]);
		f[i][1]=max(a[0][i],max(f[i-1][0],f[i-1][1])+a[0][i]);
		f[i][2]=max(a[1][i],max(f[i-1][0],f[i-1][2])+a[1][i]);
		sum=max(sum,max(f[i][0],max(f[i][1],f[i][2]))); 
	} 
//	cout<<sum<<"CCf";
	ans=max(ans,sum-2*m);
	cout<<ans<<endl;
}
int main(){
	srand(time(0));
	int _,T;cin>>_>>T;
	while(T--)	solve();
	return 0;
}