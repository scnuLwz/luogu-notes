#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 10 , INF = -3e9 - 10 , MX = 3e9;

int f[N][30],n,cnt,a[N],b[N];
map<int,int> mp;
vector<int> v[N];

void ST(){
	int k=1;
	for(int j=1;j<=25;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
		k<<=1;
	}
}
int query(int x,int y){
    if(x>y)  return MX;
	int len=y-x+1,k=log2(len);
	return min(f[x][k],f[y-(1<<k)+1][k]);
}
void solve(){
	//ai<=k-i<=ak
	//ai+i<=k<=ak+i
	//k>=ai+i  k-ak<=i
	//1 ~ k-ak  (找ai+i的最小值) -> k>=ai+i
	//mx ai+i , 1 ~ n -> (k-ak)min<=i 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=25;j++) 
		  f[i][j]=MX;
	}
	for(int i=1;i<=n;i++)  f[i][0]=i-a[i];
//	for(int i=1;i<=n;i++)  cout<<f[i][0]<<" ";
//	cout<<endl;
	ST();
    for(int i=1;i<=n;i++){
    	int sum=query(max(a[i]+i,1ll),n);
		int w=mp[sum];
		if(!w){
			cout<<0<<endl;continue;
		}
	//	cout<<sum<<"CCf"<<endl;
		bool fl=false;int ansk;
        for(int k:v[w]){
       // 	cout<<k<<" ";
        	if(k>=max(a[i]+i,1ll)&&k<=n){
        		fl=true;ansk=k;break;
			}
		}
       // cout<<ansk<<"CCF"<<endl;
        if(sum<=i&&fl){
        	cout<<1<<" "<<ansk-i<<endl;
		}
		else cout<<0<<endl;
        //cout<<1<<" "<<v[w][p]<<endl;
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!mp[i-a[i]])  mp[i-a[i]]=++cnt;
		v[mp[i-a[i]]].push_back(i);
	}  
//	for(int i=1;i<=n;i++){
//		int w=mp[i-a[i]];
//		int p=(lower_bound(v[w].begin(),v[w].end(),1)-v[w].begin());
//		cout<<p<<endl;
//	}
	solve();
	return 0;
}