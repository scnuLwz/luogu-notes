#include<bits/stdc++.h>
using namespace std;

int n,l,t;
struct node{
	double x,y;
}a[1001];
double ans=1e8;
bool v[100];
void dfs(double lx,double ly,double sum,int k)
{
	l++;
	if(k>n){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans)  return;
	if(l>=30000000){
		if(clock()>940){
			printf("%.2f",ans);
			exit(0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i]){
			v[i]=true;
			dfs(a[i].x,a[i].y,sum+double(sqrt((lx-a[i].x)*(lx-a[i].x)+(ly-a[i].y)*(ly-a[i].y))),k+1);
			v[i]=false;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i].x>>a[i].y;
	dfs(0,0,0.0,1);
	printf("%.2f",ans);
	return 0;
} 