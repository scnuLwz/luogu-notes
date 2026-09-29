#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

int ans,sum,T,n,m,L,vh,p[N];

struct num{
	int l,r;
}a[N];
struct node{
	int d,v,a;
}c[N];
vector<int> cnt[N],b[N];
bool g[N],vis[N];
bool fs;

inline bool cmp(num p,num q){
	if(p.r!=q.r)  return p.r<q.r;
	else return p.l<q.l;
}
void solve(){
	cin>>n>>m>>L>>vh;ans=sum=0;memset(p,0,sizeof p);memset(c,0,sizeof c);
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++)   cin>>c[i].d>>c[i].v>>c[i].a;
	for(int i=1;i<=m;i++)  cin>>p[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!c[i].a){
		    if(c[i].v<=vh)  continue;
			int w=lower_bound(p+1,p+m+1,c[i].d)-p;
			if(p[w]>=c[i].d){
				++ans;a[++cnt]={w,m};
			//	cout<<i<<" ";
			}
		}
		if(c[i].a>0){
			int l=1,r=m;bool fs=false;
	        while(l<r){
	        	//cout<<l<<" "<<r<<" "<<i<<endl;
		        int mid=(l+r)>>1;
		        if(p[mid]<c[i].d){
		        	l=mid+1;
		        	continue;
				}
		        if(c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d)>vh*vh){
			        r=mid;fs=true;
		        }  
		        else l=mid+1;
		    }
		    //cout<<l<<" ccf "<<i<<endl;
		    if(c[i].v*c[i].v+2*c[i].a*(p[l]-c[i].d)>vh*vh&&l<=m&&p[l]>=c[i].d){
		    	++ans;a[++cnt]={l,m};//cout<<i<<" ";
			}
	    }
	    if(c[i].a<0){
	    	int l=1,r=m;bool fs=false;
	    	int w=lower_bound(p+1,p+m+1,c[i].d)-p;
	        while(l<r){
		        int mid=(l+r+1)>>1;
		        if(p[mid]<c[i].d){
		        	l=mid+1;
		        	continue;
				}
		        if(c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d)>vh*vh){
		        	l=mid;fs=true;
				} 
				else r=mid-1;
	        }
	      //  cout<<r<<" ccf "<<i<<endl;
	        if(c[i].v*c[i].v+2*c[i].a*(p[w]-c[i].d)>vh*vh&&c[i].v*c[i].v+2*c[i].a*(p[r]-c[i].d)>vh*vh&&w<=r){
	        	++ans;a[++cnt]={w,r};
	           // cout<<i<<" ";
			}
	    }
	}
	sort(a+1,a+ans+1,cmp);
	int lst=0;
	for(int i=1;i<=ans;i++){
		if(a[i].l<=lst)  continue;
		lst=a[i].r;
		sum++;
	} 
    cout<<ans<<" "<<m-sum<<endl;
}
signed main(){
//	freopen("detect4.in","r",stdin);
//	freopen("detect.out","w",stdout);
	cin>>T;while(T--)  solve();
	return 0;
}