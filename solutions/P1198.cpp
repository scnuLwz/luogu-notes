#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int n,m,s[N],top,t[N<<2],last;

void add(int p,int l,int r,int x,int c){
    if(l==r&&l==x){
        t[p]=c;
        return;
    }
    if(l>x||r<x)  return;
    int mid=(l+r)>>1;
    add(p<<1,l,mid,x,c);add(p<<1|1,mid+1,r,x,c);
    t[p]=max(t[p],max(t[p<<1],t[p<<1|1]));
}
int ser(int p,int l,int r,int x,int y){
    if(l>=x&&r<=y)  return t[p];
    if(l>y||r<x)  return 0;
    int mid=(l+r)>>1;
    return max(ser(p<<1,l,mid,x,y),ser(p<<1|1,mid+1,r,x,y));
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    string c;
	    int x;
	    cin>>c>>x;
	    if(c=="A"){
	        //s[++top]=(t+x)%m;
	        add(1,1,N-1,++top,(last+x)%m);
	    }
	    else{
	       cout<<ser(1,1,N-1,top-x+1,top)<<endl;
	       last=ser(1,1,N-1,top-x+1,top);
	    }
	}
	return 0;
}

