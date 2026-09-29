#include <bits/stdc++.h>


using namespace std;

const int INF = 1e9 + 10 , N = 2e4 + 10;
int n,k,q[N],cnt=0,l;
struct node{
	int x,y,id;
}a[N];

inline bool cmp(node p,node q){
	return p.y-p.x<q.y-q.x;
} 
void solve(){
	cin>>n>>k;int minn=INF;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		minn=min(minn,a[i].y);a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++)  cout<<a[i].x<<" "<<a[i].y<<endl;
	l=0;
	for(int i=k;i<=min(1000000000,minn);i++){
		bool fl=true;l++;
		cnt=0;
	    for(int j=1;j<=n;j++){
		    if(a[j].x/i==a[j].y/i){
			    if(a[j].x%i==0)  q[a[j].id]=a[j].x;
			    else if(a[j].y%i==0)  q[a[j].id]=a[j].y;
			    else{
			    	fl=false;break;
				} 
		    }
		    else q[a[j].id]=a[j].y/i*i; 
		}
		if(fl){
			cout<<"Yes"<<endl;
	        for(int j=1;j<=n;j++)  cout<<q[j]<<" ";
	        cout<<endl;return;
		} 
		if(l>5e7)  break;
	}
    cout<<"No"<<endl;  
}
signed main(){
	cin.tie(0);cout.tie(0);
	int T;cin>>T;  
	while(T--)  solve();
    return 0;
}