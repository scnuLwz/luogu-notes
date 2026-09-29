#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10 , M1 = 31 , M2 = 21 , INF = 1e9 + 7;

int n,q,fac1[M1+10],fac2[M2+10];
double Ans[N];
struct num{
	int x,id;
}w[N];
struct node{
	int x,t,lx;
}a[N];
double f[N][M1][M2];

double min(double a,double b){
	if(a>b)  swap(a,b);
	return a;
}
double calc(int x,int ed){
	if(!x)  return -1;
	double sum=INF;
	for(int i=0;i<=30;i++){
		for(int j=0;j<=20;j++){
			if(f[x][i][j]>=INF)  continue;
			sum=min(sum,f[x][i][j]+(ed-a[x].x)/1.0/(fac1[i]*fac2[j]));
		}
	}
	return sum;
}
void solve(){
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=30;j++)
	    for(int k=0;k<=20;k++)
	      f[i][j][k]=double(INF+10); 
	for(int i=0;i<=n;i++)  f[i][0][0]=a[i].x;
	fac1[0]=fac2[0]=1;
	for(int i=1;i<M1;i++)  fac1[i]=fac1[i-1]*2;
	for(int i=1;i<M2;i++)  fac2[i]=fac2[i-1]*3;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			for(int k=0;k<=20;k++){
			    //printf("%.6f",f[i-1][j][k]);cout<<" "<<i-1<<" "<<j<<" "<<k<<"CCf"<<endl;
				f[i][j][k]=min(f[i-1][j][k]+(a[i].x-a[i-1].x)/1.0/(fac1[j]*fac2[k]),f[i][j][k]);
			    if(a[i].lx==1)	continue;
				if(a[i].lx==2&&j>0)  f[i][j][k]=min(f[i-1][j-1][k]+a[i].t*1.0+(a[i].x-a[i-1].x)/1.0/(fac1[j-1]*fac2[k]),f[i][j][k]);
				if(a[i].lx==4&&j>1)  f[i][j][k]=min(f[i-1][j-2][k]+a[i].t*1.0+(a[i].x-a[i-1].x)/1.0/(fac1[j-2]*fac2[k]),f[i][j][k]);
				if(a[i].lx==3&&k>0)  f[i][j][k]=min(f[i-1][j][k-1]+a[i].t*1.0+(a[i].x-a[i-1].x)/1.0/(fac1[j]*fac2[k-1]),f[i][j][k]);
			}                 
		}
	} 
	int j=1,lsty=-1;
	for(int i=1;i<=q;i++){
		double ans=w[i].x*1.0;
		while(a[j].x<w[i].x&&j<=n){
			j++;
		}
		double t=calc(j-1,w[i].x);
		if(t==-1)  t=w[i].x*1.0;
		Ans[w[i].id]=t;
	}
	for(int i=1;i<=q;i++)  printf("%.12f\n",Ans[i]);
}
inline bool cmp(num p,num q){
	return p.x<q.x;
}
signed main(){
//	freopen("ship4.in","r",stdin);
//	freopen("ship.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)  cin>>a[i].x>>a[i].t>>a[i].lx;
	for(int i=1;i<=q;i++){
		cin>>w[i].x;
		w[i].id=i;
	}  
	sort(w+1,w+q+1,cmp);solve();
    return 0;
}