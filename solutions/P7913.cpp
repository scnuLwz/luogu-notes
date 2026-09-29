#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int k,n,m,f[N],g[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
struct node{
	int x,y;
}a[N],b[N];
typedef pair<int,int> PII;
void solve(node a[],int n,int res[]){
    priority_queue<PII,vector<PII>,greater<PII> > fl;
	priority_queue<int,vector<int>,greater<int> > lq;
    for(int i=1;i<=k;i++)  lq.push(i);
    for(int i=1;i<=n;++i){
    	while(fl.size()&&a[i].x>=fl.top().first){
    		lq.push(fl.top().second);
    		fl.pop();
		}
		if(!lq.size())  continue;
		int t=lq.top();lq.pop();
		res[t]++;
		fl.push({a[i].y,t});
	}
	for(int i=1;i<=k;i++)  res[i]+=res[i-1];
//	for(int i=1;i<=n;i++)  cout<<res[i]<<" ";
}
inline bool cmp(node p,node q){
	return p.x<q.x;
}
signed main(){
	k=read();n=read();m=read();
	for(int i=1;i<=n;i++)  a[i].x=read(),a[i].y=read();
	for(int i=1;i<=m;++i)  b[i].x=read(),b[i].y=read();
	sort(a+1,a+n+1,cmp);sort(b+1,b+m+1,cmp);
	solve(a,n,f);solve(b,m,g);
	int ans=0;
	for(int i=0;i<=k;i++)  ans=max(ans,f[i]+g[k-i]);
	cout<<ans; 
	return 0;
}