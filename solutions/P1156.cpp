#include<bits/stdc++.h>

using namespace std;

const int N = 1010 , M = 40;

struct node{
	int t,val,h;
}a[N];
int f[N][N],n,m;

inline bool cmp(node p,node q){
	return p.t<q.t;
}
signed main(){
	memset(f,-1,sizeof f);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i].t>>a[i].val>>a[i].h;
	a[++n]={0,10,0};
	sort(a+1,a+n+1,cmp);
	f[1][0]=10;//前i个堆成j的高度 
	for(int i=2;i<=n;i++){
	    for(int k=1;k<i;k++){
	    	for(int j=m;j>=0;j--){
			    if(f[k][j]==-1)  continue;
			    int p=max(f[i][j+a[i].h],f[k][j]);
			    if(p>=a[i].t)
			      f[i][j+a[i].h]=p;
			    p=max(f[i][j],f[k][j]+a[i].val);
			    if(f[k][j]>=a[i].t)
			      f[i][j]=p;
		    }
		}		
	}
//	for(int i=1;i<=n;i++,cout<<endl)
//	  for(int j=0;j<=m;j++)
//	    cout<<f[i][j]<<" ";
	int ans=1e9;
	for(int i=1;i<=n;i++)
	  for(int j=m;j<=m+M;j++)
	    if(f[i][j]!=-1)
		  ans=min(ans,min(f[i][j],a[i].t));
	if(ans<1e9)  cout<<ans; 
    else{
    	ans=0;
    	for(int i=1;i<=n;i++)
    	  for(int j=0;j<=m+M;j++)
    	    ans=max(ans,f[i][j]);
    	cout<<ans;
	}	
	return 0;
}