#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n,m,be,q[N],sum[N];
set<int> s;
struct node{
	int x,y;
}a[N];

inline bool cmp(node p,node q){
	if(p.x!=q.x)  return p.x<q.x;
	else return p.y<q.y;
}
bool v1[N],v2[N];
signed main(){
    cin>>n>>m>>be;
    for(int i=1;i<=m;++i){
    	cin>>a[i].x>>a[i].y;
		if(a[i].x>a[i].y)  swap(a[i].x,a[i].y);
    	v1[a[i].y]=v2[a[i].x]=true;
		q[a[i].x]++,q[a[i].y+1]--;
	}
	sort(a+1,a+m+1,cmp);
//	for(int i=1;i<=m;i++)
//	  cout<<a[i].x<<" "<<a[i].y<<endl;
    for(int i=1;i<=n;i++)  q[i]+=q[i-1];
	for(int i=1;i<=n;i++)
	  if(!q[i])
	    sum[i]=-1e9;
    for(int i=1;i<=n;i++)  sum[i]=sum[i]+q[i-1]; 
    //for(int i=1;i<=n;i++)  cout<<sum[i]<<" ";
    for(int i=be+1;i<=n;i++){
    	if(q[i]&&v1[i])
    	  s.insert(i);
    	else if(!q[i])  break;
	}
	for(int i=be-1;i>=1;i--){
		if(v2[i]&&q[i])
		  s.insert(i);
		else if(!q[i])  break;
	}
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	  cout<<*it<<" ";
	return 0;
}