#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10 , mod = 998244353;
int n,m,T,f[N][N],ansc,ansf,id,g[N][N];
char a[N][N];
int C,F;
int main() {
	cin>>T>>id;
	while(T--){
		ansc=ansf=0;
		memset(g,0,sizeof g);
		memset(f,0,sizeof f);
		cin>>n>>m>>C>>F;
		if(!C&&!F){
			cout<<0<<" "<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
	        cin>>a[i][j];
	    for(int i=1;i<=n;i++)
	      for(int j=m-1;j>=1;j--){
	      	if(a[i][j]=='1')  f[i][j]=-1;
	      	else if(a[i][j+1]=='0')  f[i][j]=f[i][j+1]+1;
		  }
		for(int i=n;i>=1;i--)
		  for(int j=1;j<=m;j++){
		  	if(a[i][j]=='1')  g[i][j]=-1;
		  	else if(a[i+1][j]=='0')  g[i][j]=g[i+1][j]+1;
		  }
//		for(int i=1;i<=n;i++,cout<<endl)
//		  for(int j=1;j<=m;j++)
//		    cout<<g[i][j]<<" ";
//		for(int i=1;i<=n;i++,cout<<endl)
//		  for(int j=1;j<=m;j++)
//		    cout<<f[i][j];
        for(int j=1;j<m;j++){
        	int lc=0,lf=0;
        	for(int i=1;i<=n;i++){
        		if(f[i][j]==-1){
        			lc=lf=0;
        			continue;
				}
				ansc=(ansc+f[i][j]*lc)%mod;
				//cout<<i<<" "<<j<<" "<<f[i][j]*lc<<endl;
				ansf=(ansf+lf)%mod;
				lf=(lf+f[i][j]*lc)%mod;
				lc+=max(0,f[i-1][j]);
			}
		}cout<<(ansc*C)%mod<<" "<<(ansf*F)%mod<<endl;
	}
    return 0;
}
