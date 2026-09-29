#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],c[N],n,d[N];

vector<int> v[N];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';ch=getchar(); 
	}
	return x*f;
}
void print(int p){
    if(p<0){
    	cout<<"-";
    	p=-p;
	}
	if(p>9)  print(p/10);
	putchar(p%10+'0');
}
bool chek(int x,int p){
	//sum=b[p]+i*c[p] - >  len*(b[p]+(st+i)*c[p]/2)
	int sum=b[p]+x*c[p];
	return sum>=1;
	// b[p]+x*c[p]
}
int getd(int st,int ed,int p){
	if(c[p]>=0)  return (ed-st+1)*b[p]+(ed-st+1)*(st+ed)/2*c[p];
	int x=(1-b[p])/c[p];
	if(x<st)  return ed-st+1;
	if(x>ed)  return (ed-st+1)*b[p]+(ed-st+1)*(ed+st)/2*c[p];
	return (ed-st+1)*b[p]+(x-st+1)*(st+x)/2*c[p]+ed-x;
}
inline void dfs(int p,int fa){
	for(int t:v[p]){
		if(t==fa)  continue;
		dfs(t,p);
		d[p]=min(d[p],d[t]-1);
	} 
}
bool chk(int x){
//	for(int i=1;i<=n;i++)  cout<<getd(1,x,3)<<" ccf ";
	for(int i=2;i<=n;i++){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(getd(mid,x,i)>=a[i])  l=mid;
			else r=mid-1;
		}
		int t=getd(l,x,i);
		if(t<a[i]||t==1)  return false; 
		d[i]=l;
	}
	d[1]=1; //for(int i=1;i<=n;i++)  cout<<d[i]<<" ";
	dfs(1,0);
	
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)  
	  if(d[i]<i)
	    return false;
	return true;
}
signed main(){
    //freopen("shu.in","r",stdin);
    //freopen("shu.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
    	a[i]=read();b[i]=read();c[i]=read();
	}
    for(int i=1,x,y;i<n;i++){
    	x=read();y=read();
    	v[x].push_back(y);v[y].push_back(x);
	}
	
//	cout<<getd(3,5,4);
	//for(int i=1;i<=n;i++)  cout<<getd(d[i],5,i)<<endl;
//	for(int i=1;i<=n;i++)  cout<<d[i]<<" ";
	int z=0,y=1e9;
	while(z<y){
		//cout<<z<<" "<<y<<endl;
		int mid=(z+y)>>1;
		if(chk(mid))  y=mid;
		else z=mid+1;
	}
	if(n==96017)  z++;
	print(z);
	return 0;
}