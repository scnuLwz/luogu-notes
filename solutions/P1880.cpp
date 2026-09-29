#include<bits/stdc++.h>

using namespace std;

const int N = 210;
int n,f[N][N],a[N],g[N][N];

int cal(int s,int t){
	int S=0;
	for(int i=s;i<=t;i++)  S+=a[i];
	return S;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int len=2;len<=2*n;len++){
		for(int i=1;i+len-1<=2*n;i++)
		{
			int j=i+len-1;
			g[i][j]=0x3f3f3f3f;
			for(int k=i+1;k<=j;k++){
				f[i][j]=max(f[i][j],f[i][k-1]+f[k][j]+cal(i,j));
				g[i][j]=min(g[i][j],g[i][k-1]+g[k][j]+cal(i,j));
			}
			  
		}
	}
	int ans=1e9;
	for(int i=1;i<=n;i++)  ans=min(ans,g[i][i+n-1]);
	cout<<ans<<endl;
	ans=0;
	for(int i=1;i<=n;i++)  ans=max(ans,f[i][i+n-1]);
	cout<<ans;
	return 0;
} 