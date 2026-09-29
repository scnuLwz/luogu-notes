#include<bits/stdc++.h>
#define rep(i,x,y)  for(int i=x;i<=y;i++)
using namespace std;

int find(int u);
const int N = 1e6 + 10;

int Q,id,n,m,T,U,val[N],fa[N];

bool chk(int x,int y){
	return find(x)==find(y);
}
int find(int u){
	if(fa[u]==u)  return u;
	return fa[u]=find(fa[u]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
void solve(){
	cin>>n>>m;
	T=n+1;U=n+2; 
	rep(i,1,n)  val[i]=i;
	rep(i,1,m){
		char opt;
		int x,y;
		cin>>opt;
		if(opt=='+'||opt=='-'){
			cin>>x>>y;
			if(opt=='+')  val[x]=val[y];
			else val[x]=-val[y];
		}else{
			cin>>x;
			if(opt=='U')  val[x]=U;
			else val[x]=T;
		//	cout<<val[x]<<"ccf"<<endl;
		} 
	}rep(i,1,2*n)  fa[i]=i;
	rep(i,1,n){
		if(abs(val[i])==U)  merge(i,i+n);
		else if(abs(val[i])==T)  continue;//合法 
		else{
			if(val[i]>0){  //相等关系 
				merge(val[i],i);merge(val[i]+n,i+n);
			}if(val[i]<0){
				merge(-val[i],i+n);merge(-val[i]+n,i);
			}
		}
	}
//    rep(i,1,n){
//        if (abs(val[i]) == U){
//        	merge(i, i+n);
//		} 
//        else if (abs(val[i]) == T) continue;
//        else if (val[i] > 0) {
//            merge(val[i], i); 
//            merge(val[i]+n, i+n);
//        }
//        else if (val[i] < 0) {
//            merge(-val[i], i+n);
//            merge(-val[i]+n, i);
//        }
//    }

	int ans=0;
	rep(i,1,n) 
	  if(chk(i,i+n))
	    ans++;
	cout<<ans<<endl;
}
int main(){
	cin>>id>>Q;
	for(;Q;Q--,solve());
	return 0;
}