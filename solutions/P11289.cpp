#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long
using namespace std;

const int N = 1e6 + 10 , INF = 1e18;

int n,m;
struct node{
	int l,t,id;
}a[N];

int sum[N],tag[N];
struct SEG{
	void update(int p,int l,int r,int x,int y,int k){
		if(l>=x&&r<=y){
			sum[p]=k;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)  update(ls,l,mid,x,y,k);
		if(y>mid)  update(rs,mid+1,r,x,y,k);
		sum[p]=min(sum[rs],sum[ls]);
	}
	int query(int p,int l,int r,int x,int y){
		if(l>=x&&r<=y)  return sum[p];
		int mid=l+r>>1,ans=INF;
		if(x<=mid)  ans=min(ans,query(ls,l,mid,x,y));
		if(y>mid)  ans=min(ans,query(rs,mid+1,r,x,y));
		return ans;
	}
}st; 
vector<int> ans[N]; 
inline bool cmp(node p,node q){
	return p.t<q.t;
}

void solve(){
	for(int i=1;i<=n;i++){
		int l=1,r=m;
		while(l<r){
			//cout<<l<<' '<<r<<endl;
			int mid=(l+r)>>1;
			if(st.query(1,1,m,1,mid)<=a[i].t)  r=mid;
			else l=mid+1;
		}
		if(st.query(1,1,m,l,l)<=a[i].t){
			st.update(1,1,m,l,l,a[i].t+a[i].l);
		    ans[l].push_back(a[i].id);
		}
		else{
			int l=1,r=m,ti=INF,to;
			while(l<r){
				int mid=l+r>>1;
				if(st.query(1,1,m,1,mid)<=st.query(1,1,m,mid+1,r)){
					r=mid;
				}
				else l=mid+1;
			}
			ans[l].push_back(a[i].id);st.update(1,1,m,l,l,st.query(1,1,m,l,l)+a[i].l);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i].size()<<" ";
		sort(ans[i].begin(),ans[i].end());
		for(int j:ans[i])  cout<<j<<" ";
		cout<<endl;  
	}
} 
signed main(){
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].t;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	solve();
	return 0;
}