#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 15 , M = 1 << 12 + 10, mod = 1e8;

int f[N][M],n,m,g[N][N];
void solve(){
//	for(int S=0;S<(1<<m);S++){
//		bool fs=true;
//		for(int i=1;i<=m;i++)
//		  if(!g[1][i]&&(S&(1<<(i-1))))
//            fs=false;
//        f[1][S]=fs;
//	}
    f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int S=0;S<(1<<m);S++){
			bool fl=true;
			for(int k=1;k<=m;k++)
			  if((S&(1<<(k-1)))&&!g[i][k]){
			  	fl=false;
			  	break;
			  }
			for(int k=2;k<=m;k++){
				if((S&(1<<(k-1)))&&(S&(1<<(k-2)))){
					fl=false;
					break;
				}
			}
			if(!fl)  continue;
//			cout<<zh(S)<<" "<<i<<endl;
			for(int _S=0;_S<(1<<m);_S++){
				bool fs=true;
				for(int j=2;j<=m;j++){
					if((_S&(1<<(j-1)))&&(_S&(1<<(j-2)))){
						fs=false;
						break;
					}
				}
				for(int j=1;j<=m;j++){
					if((_S&(1<<(j-1)))&&(!g[i-1][j])){
						fs=false;
						break;
					}
				}
				for(int j=1;j<=m;j++){
					if((S&(1<<(j-1)))&&(_S&(1<<(j-1)))){
						fs=false;
						break;
					}
				}
				if(!fs)  continue;
				//cout<<zh(_S)<<" "<<zh(S)<<endl;
				f[i][S]=(f[i][S]+f[i-1][_S])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++)  ans=(ans+f[n][i])%mod;
	cout<<ans;
}
signed main(){
	cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>g[i][j];
    solve();
	return 0;
}