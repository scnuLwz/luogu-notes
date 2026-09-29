#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n,m,b,h,dis[N],w[N];
int f[N];
struct node{
	int to,w;
};
vector<node> v[N];

bool chk(int p){
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	queue<int> q;
	q.push(1);
	f[1]=true;
	while(q.size()){
		int l=q.front();
		q.pop();
		f[l]=false;
		for(node k:v[l]){
			if(dis[k.to]>dis[l]+k.w){
				if(w[k.to]>p||w[l]>p)
				  continue;
				dis[k.to]=dis[l]+k.w;
				if(!f[k.to]){
					f[k.to]=true;
					q.push(k.to);
				}
			}
		}
	}
	return dis[n]<=b;
} 

int main(){
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		h=max(h,w[i]);
	}
	  
	while(m--){
		int s,t,w;
		cin>>s>>t>>w;
		v[s].push_back({t,w});
		v[t].push_back({s,w});
	}
	int z=0,y=h;
	while(z<y){
		int mid=(z+y)>>1;
		if(chk(mid)) y=mid;
		else z=mid+1; 
	}
	if(chk(z))
	  cout<<z;
	 else cout<<"AFK";
	return 0;
} 