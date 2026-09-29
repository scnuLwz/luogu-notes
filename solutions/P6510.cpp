#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10; 
int n,a[N],s1[N],t1,s2[N],t2,ans;

void work(){
	for(int i=1;i<=n;i++){
		while(t1>0&&a[s1[t1]]>=a[i])  t1--;
		while(t2>0&&a[s2[t2]]<a[i])  t2--;
		int k=lower_bound(s1+1,s1+t1+1,s2[t2])-s1;
	    if(k!=(t1+1)){
	    	ans=max(ans,i-s1[k]+1);
		}
		s1[++t1]=i;s2[++t2]=i;
	}
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    work();
    cout<<ans;
	return 0;
}