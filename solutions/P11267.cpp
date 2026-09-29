#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7 , N = 1e6 + 10;

int n,m,q;
__int128 f[65][N];
int h[N],a[N];
void print(__int128 x){
	if(x>9)  print(x/10);
	putchar(x%10+'0');
}

void build(){
	for(int i=0;i<n;i++){
		int nxt=(i+m)%n;
		f[0][i]=max(i+1,i+m-nxt+h[nxt]);
	}
	for(int i=1;i<62;i++){
		for(int j=0;j<n;j++){
			int k=f[i-1][j]%n;
			f[i][j]=f[i-1][k]-k+f[i-1][j];
		}
	}
}
__int128 query(int s,int k){
	__int128 ans=s-1;
	for(int i=0;k;k>>=1,i++){
		if(k&1){
			int T=ans%n;
			ans=f[i][T]-T+ans;
		}
	}
	return (ans+1)%mod;
}
signed main(){
	cin>>n>>m>>q;int lst=-m;
	for(int i=0;i<n;i++){
		char c;cin>>c;
		if(c=='1'){
			lst=i;
			h[i]=i;
		}
		else h[i]=lst;
	}
	if(lst!=-m)  for(int i=0;h[i]==-m&&i<n;i++)  h[i]=lst-n;//前面的相对位置 
	build();
	while(q--){
		int s,t;cin>>s>>t;
		print(query(s,t));cout<<endl;
	} 
	return 0;
}