#include<bits/stdc++.h>

using namespace std;

const int N = 101000;
int T,n,a[N],f[N];
int main(){
	cin>>T;
	while(T--){
		memset(f,0,sizeof f);
		f[0]=1;int sum=0;
		cin>>n;
        for(int i=1;i<=n;++i){
        	cin>>a[i];
        	sum=max(sum,a[i]);
		} 
		sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
          for(int j=a[i];j<=sum;j++)
            f[j]+=f[j-a[i]];
        int ans=0;
        for(int i=1;i<=n;i++)
           if(f[a[i]]==1)
             ans++;
        cout<<ans;
        putchar(10);
	}
	return 0;
}