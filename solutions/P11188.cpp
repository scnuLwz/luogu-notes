#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10 , INF = 1e5 * 1e5 * 10;

int a[N],t[N],n,val[20],id,b[N],ans,sum;
bool vis[N];

bool chk(int k){
	if(k==1)  return true;
	int p=1;
	for(int i=1;i<=n;i++){
		if(a[i]==b[p])  p++;
	}
	return p==k;
}
void dfs(int k,int ws){
//    if(!chk(k))  return;
	if(k>ws){
	    if(!chk(k))  return;
	    int ss=0,s=0;
		for(int i=1;i<=ws;i++){
			ss=ss*10+b[i];s+=val[b[i]];
		}  
		ans=min(ans,sum+ss-s);
//		if(sum+ss-s==477487){
		//	for(int i=1;i<=ws;i++)  cout<<b[i]<<" ";
		//	cout<<endl;
		 //   cout<<ss<<" "<<s<<" "<<sum+ss-s<<endl;
//		}
		
		return;
	}	
	
	for(int i=1;i<=9;i++){
		if(!t[i])  continue;
		b[k]=i;dfs(k+1,ws);
	}
}
void sub1(int w){
	for(int i=0;i<=w;i++){  //代替0位 - w位 
	    if(!i){
	    	ans=sum;
	    	continue;
		}
		for(int j=1;j<=n;j++)  vis[j]=false;
		int h=0,lst=0;
		for(int k=i-1;k>=0;k--){
			int s=INF,idw;
			for(int j=1;j<=n;j++){
				if(pow(10,k)*a[j]-val[a[j]]<s&&!vis[j]){
					s=pow(10,k)*a[j]-val[a[j]];
				    idw=j;
				}
			}
			vis[idw]=true;
			h+=s;lst=idw;
			//cout<<idw<<" "<<k<<endl;
		}
		//cout<<h<<" "<<i<<endl;
		ans=min(ans,sum+h);
	}
}
void solve(){
	memset(t,0,sizeof t);memset(vis,false,sizeof vis);memset(b,0,sizeof b);
	string s;cin>>s;s=" "+s;n=s.size()-1;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-48; 
		t[a[i]]++;
	}  
	int maxn=0;sum=0;
	for(int i=1;i<=9;i++){
		cin>>val[i];
	} 
	for(int i=1;i<=n;i++){
		sum+=val[a[i]];
		maxn=max(maxn,val[a[i]]);
	}  
	int mn=maxn,w=0;ans=sum;
	while(mn){
		w++;
		mn/=10;
	}
	if(w==6)  --w;
	if(id>=14&&id<=25){
		sub1(w);
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=w;i++)  dfs(1,i);
        cout<<ans<<endl;
	}
}
signed main(){
	int T;cin>>id>>T;
    for(;T;T--)  solve();
	return 0;
}