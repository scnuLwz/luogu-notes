#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t[31][N],n,m,q,tq[31][N],ans;
char a[N][31];

inline int read(){
	int x=0,f=1;
	char t=getchar(); 
	while(t<'0'||t>'9')
	{
		if(t=='-')  f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		x=x*10+t-'0';
		t=getchar();
	}
	return x*f;
}
inline void add(int x,int y,int i){
	for(;x<=m;x+=x&-x)
	  t[i][x]+=y;
}
inline int ser(int x,int i){
	int ans=0;
	for(;x;x-=x&-x)
	  ans+=t[i][x];
	return ans; 
}
inline int get(int l,int r,int i){
	int ans=ser(r,i)-ser(l-1,i);
	return ans;
}
inline void _add(int x,int y,int i){
	for(;x<=m;x+=x&-x)
	  tq[i][x]+=y;
}
inline int _ser(int x,int i){
	int ans=0;
	for(;x;x-=x&-x)
	  ans+=tq[i][x];
	return ans; 
}
inline int _get(int l,int r,int i){
	return _ser(r,i)-_ser(l-1,i);
}
signed main(){
	n=read();m=read();q=read();
	for(int i=1;i<=m;i++){
		scanf("%s",a[i]+1);
    }
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++){
      	if(a[i][j]=='1')
      	  add(i,1,j);
      	else if(a[i][j]=='?')
      	  _add(i,1,j);
	  }
	for(int i=1,opt,l,r;i<=q;i++){
		opt=read();l=read();
		if(opt==0){
			r=read();
			int sum=1;
			for(int j=1;j<=n;j++)
			{
				if(get(l,r,j)+_get(l,r,j)!=r-l+1&&get(l,r,j)){
					sum=0;
					break;
				}
				if(_get(l,r,j)==r-l+1)
				  sum<<=1;
			}
		    if(sum)  ans^=sum;
		}
		else{
			char s[31];
			scanf("%s",s+1);
			for(int j=1;j<=n;j++){
				if(a[l][j]=='?')
				  _add(l,-1,j);
				if(a[l][j]=='1')
				  add(l,-1,j);
			}
			for(int j=1;j<=n;j++){
				if(s[j]=='?')
				  _add(l,1,j);
				if(s[j]=='1')
				  add(l,1,j);
			}
			for(int j=1;j<=n;j++)  a[l][j]=s[j];
		}
	}
	return cout<<(ans^0),0;
}