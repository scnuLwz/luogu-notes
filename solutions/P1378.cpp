#include<bits/stdc++.h>

using namespace std;
const double pi=3.1415926535;
const int N = 20;
int n,bx,by,ex,ey;
double a[N],b[N],r[N],ans;
bool v[N];
double get_w(int p,int q){
	return sqrt((a[p]-a[q])*1.0*(a[p]-a[q])+(b[p]-b[q])*1.0*(b[p]-b[q]));
}
double minp(double a,double b){
	if(a>b)  return b;
	else return a;
}
double max(double a,double b){
	if(a>b)  return a;
	else return b;
}
double get(int x){
	//10 20 0 10
	double R=min(min(abs(ey-b[x]),abs(b[x]-by)),min(abs(ex-a[x]),abs(a[x]-bx)));
	for(int i=1;i<=n;i++){
		if(i!=x&&v[i]==true){
			R=minp(R,max(get_w(x,i)-r[i],0.0));
		}
	}
	return R;
}
void dfs(int k,double s){
	if(k>n){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			r[i]=get(i);
			v[i]=true;
			dfs(k+1,s+r[i]*r[i]*pi);
			v[i]=false;
			r[i]=0;
		}
	}
}
int main(){
	cin>>n>>bx>>by>>ex>>ey;
	if(bx>ex)  swap(bx,ex);
	if(by>ey)  swap(by,ey);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	dfs(1,0.0);
	return cout<<int((ex-bx)*(ey-by)-ans+0.5),0;
}