#include<bits/stdc++.h>
#define rep(i,x,y)  for(int i=x;i<=y;i++)
using namespace std;

const int N = 21 , M = 2010;

int a[N],n,m,ans;
bitset<M> f;
int main(){
	cin>>n>>m;
    rep(i,1,n)  cin>>a[i];
	rep(S,1,(1<<n)-1){
		int sum=0;
		rep(i,1,n)
		  if(S&(1<<(i-1)))
		    ++sum;
		if(sum!=n-m)  continue;
		f.reset();
		f[0]=1;
		rep(i,1,n)
		  if(S&(1<<(i-1)))
		    f|=(f<<a[i]);
		ans=max(ans,(int)f.count()-1);
	}  
	cout<<ans;
	return 0;
}