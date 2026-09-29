#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;

int f[N],ans,w[N][27],last[N],n;
char s[N];
signed main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
    	last[i]=i;
    	int x=w[last[i-1]][s[i]-'a'];
    	if(x)  last[i]=last[x-1],f[i]=f[x-1]+1;
		w[last[i]][s[i]-'a']=i;
    	ans+=f[i];
	}cout<<ans;
	return 0;
}