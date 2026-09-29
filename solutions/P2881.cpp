#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n,m,f[N][N],ans;
int main(){
	memset(f,0x3f,sizeof f);
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		f[y][x]=1;
	}
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		  if(f[i][j]<1e8)
		    ans++;
	//	if(sum==2)  cout<<i<<" ";
	//	ans=min(ans,sum);
	}
	cout<<n*(n-1)/2-ans;
	return 0;
}