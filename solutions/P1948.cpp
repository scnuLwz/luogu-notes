#include<bits/stdc++.h>
using namespace std;

const int N =  1e3 + 10;
int n,p,k,l,r;
struct node{
	int y,w;
};
struct num{
	int d,s,maxn;
};
vector<node> v[N];
int g[N][N*10];
bool chk(int x){
    queue<num> q; 
    memset(g,0x3f,sizeof g);
    q.push({1,0,0});
    g[1][0]=0;
    while(q.size()){
        auto l=q.front();
    	q.pop();
    	//cout<<l.d<<" "<<l.s<<" "<<l.maxn<<endl;
    	if(l.d==n){
    		return true;
		}
    	for(node t:v[l.d]){
    		int now=max(t.w,l.maxn);
    		if(now>x){
    			if(l.s<k&&l.maxn<g[t.y][l.s+1]){
    				q.push({t.y,l.s+1,l.maxn});
    				g[t.y][l.s+1]=l.maxn;
				}
			}
			else{
				if(now<g[t.y][l.s]){
					q.push({t.y,l.s,now});
					g[t.y][l.s]=now;
				}
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>p>>k;
	for(int i=1,x,y,w;i<=p;i++){
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
		r=max(r,w);
	}
	if(k>p){
		return cout<<0,0;
	}
	while(l<r){
		int mid=(l+r)>>1;
		if(chk(mid))  r=mid;
		else l=mid+1; 
	}
	if(chk(l))
	  cout<<l;
	else cout<<-1;
	return 0;
}