#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,ans;
ll o(ll x){
	ll sum=0,l,r;
	for(ll i=1;i<=x;){
		int r=x/(x/i);
		sum+=(r+i)*(r-i+1)/2*(x/i);
		i=r+1;
	}
	return sum;
}
int main(){
	scanf("%lld%lld",&x,&y);
	ans=o(y)-o(x-1);
	printf("%lld",ans);
	return 0;
}