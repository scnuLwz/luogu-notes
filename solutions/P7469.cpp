#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 3e3 + 10 , B = 1e4 + 7;
const int M = 1e14 + 31;
int n,t[N*N],ans;
char a[N],b[N];
map<int,int> mp;
signed main(){
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;i++){
		int now=0,k=1;
		for(int j=i;j<=n;j++){
			while(k<=n&&a[k]!=b[j])  k++;
			if(k>n)  break;++k;
			now=(now*B+b[j]-'a'+1)%M;
			t[++t[0]]=now;
	    }
	}sort(t+1,t+t[0]+1);ans=unique(t+1,t+t[0]+1)-t-1;
	cout<<ans;
	return 0;
}