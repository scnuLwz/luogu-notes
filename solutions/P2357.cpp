#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10; 
int n,m,a[N],s[N],st[N],ed[N],ta[N];
int bel[N];
void build(){
	int t=sqrt(n);
	for(int i=1;i<=t;i++){
		st[i]=n/t*(i-1)+1;
		ed[i]=n/t*i;
	}
	ed[t]=n;
    for(int i=1;i<=t;i++)
	  for(int j=st[i];j<=ed[i];j++) 
	    bel[j]=i; 
}
void add(int x,int y,int k){
	if(bel[x]==bel[y])
	  for(int i=x;i<=y;i++){
	  	a[i]+=k;
	  	s[bel[i]]+=k;
	  }
	else{
		for(int i=x;i<=ed[bel[x]];i++){
			a[i]+=k;
			s[bel[i]]+=k; 
		}
		for(int i=st[bel[y]];i<=y;i++){
			a[i]+=k;
			s[bel[i]]+=k;
		}
		for(int i=bel[x]+1;i<bel[y];i++)
		    ta[i]+=k;
	}
} 
int ser(int x,int y){
	int sum=0;
	if(bel[x]==bel[y]){
		for(int i=x;i<=y;i++)
		  sum+=a[i]+ta[bel[i]];
		return sum;
	}
	for(int i=x;i<=ed[bel[x]];i++)  sum+=a[i]+ta[bel[i]];
	for(int i=st[bel[y]];i<=y;i++)  sum+=a[i]+ta[bel[i]];
	for(int i=bel[x]+1;i<bel[y];++i)  sum+=s[i]+ta[i]*(ed[i]-st[i]+1);
	return sum;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	int sq=sqrt(n);
    build();
	for(int i=1;i<=sq;i++)
	  for(int j=st[i];j<=ed[i];j++)
	    s[i]+=a[j];
	for(int i=1,opt,x,y,k;i<=m;i++){
		cin>>opt;
		if(opt==1){
			cin>>x>>y>>k;add(x,y,k);
		}
		if(opt==4){
			cin>>x>>y;
			cout<<ser(x,y)<<endl;
		}
		if(opt==2){
			cin>>x;
			add(1,1,x);
		}
		if(opt==3){
			cin>>x;
			add(1,1,-x);
		}
		if(opt==5){
			cout<<ser(1,1)<<endl;
		}
	}
	return 0;
}