#include<bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;

const int N = 2e6 + 10;

int n,m,a[N],f[N],c1[N],c2[N];

struct BIT{
	void add(int x,int y,int c[]){
		for(;x<N;x+=x&-x)  c[x]+=y;
	}
	int query(int x,int c[]){
		int ans=0;
		for(;x;x-=x&-x)  ans+=c[x];
		return ans;  
	}
}bit;

void update(int x,int y){
	if(x>=1){
		bit.add(x,y,c1);
	    bit.add(x,y*x,c2);
	}
}

int ser(int x,int c[]){
    return bit.query(N-1,c)-bit.query(x-1,c);
}
signed main(){
    cin>>n>>m;
    for(int i=1,x;i<=n;i++){
    	cin>>x;
    	a[x]++;
	}
	for(int i=1;i<=n;i++)  f[a[i]]++;
	for(int i=1;i<=n;i++){
//		cout<<f[i]<<" ";
		bit.add(i,f[i],c1);bit.add(i,f[i]*i,c2); 
	}  
//	cout<<bit.query(2,c1)<<" ccf ";
	for(int i=1,opt,x;i<=m;i++){
		cin>>opt>>x;
		if(opt==1){
			f[a[x]+1]++;f[a[x]]--;
			update(a[x]+1,1);update(a[x],-1);
			a[x]++;
		}
		if(opt==2){
			f[a[x]-1]++;f[a[x]]--;
			update(a[x]-1,1);update(a[x],-1);
			a[x]--;
		}
		if(opt==3)  cout<<ser(x,c2)-x*ser(x,c1)<<endl;
	}
	return 0;
}