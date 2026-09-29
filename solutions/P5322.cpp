#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e4 + 10 , M = 110;

int f[N],n,m,s,ans,a[M][N];
int main(){
	cin>>s>>n>>m;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			a[j][i]=a[j][i]*2+1;
		}
	}
	for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+s+1);
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=0;j--)
	    for(int k=1;k<=s;k++){
	    	if(j>=a[i][k])
	          f[j]=max(f[j],f[j-a[i][k]]+k*i);
		}
	cout<<f[m];
	return 0;
}