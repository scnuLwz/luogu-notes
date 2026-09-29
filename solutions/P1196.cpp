#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
int n,m,ans,fa[N],tot[N],dis[N];//边权 

inline int find(int x){
	if(fa[x]!=x){
		int t=find(fa[x]);
		dis[x]+=dis[fa[x]];
		return fa[x]=t;
	}
	else return x;
}
inline void update(int x,int y){
	int fx=find(x),fy=find(y);
	dis[fx]+=tot[fy];//他们之间的战舰数量
	fa[fx]=fy;//认贼作父 
	tot[fy]+=tot[fx];
	tot[fx]=0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		tot[i]=1;//集合元素数量 
		fa[i]=i;
	}
	for(int i=1,x,y;i<=n;i++){
		char lx;
		cin>>lx>>x>>y;
		if(lx=='C'){
			if(find(x)==find(y))
			  cout<<abs(dis[y]-dis[x])-1<<endl;
			else puts("-1");
		}else{
			update(x,y);
		}
	}
	return 0;
}
