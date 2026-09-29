#include<bits/stdc++.h>
using namespace std;

const int N = 210;

int n;
double f[N][N],ans=1e9,maxz[N],zd[N];
struct node{
	int x,y;
}a[N];

double cal(int a,int b,int c,int d){
	return sqrt(1.0*(a-b)*(a-b)+1.0*(c-d)*(c-d));
}

void floyd(){
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      if(f[i][k]+f[k][j]<f[i][j])
	       f[i][j]=f[i][k]+f[k][j];
}
bool toget(int a,int b){
	if(f[a][b]>=1e7)  return false;
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    f[i][j]=1e9;
	for(int i=1;i<=n;i++)
	  cin>>a[i].x>>a[i].y;
   // cout<<cal(a[7].x,a[6].x,a[7].y,a[6].y);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++){
	  	char c;
	  	cin>>c;
	  	if(c=='1')
	  	  f[i][j]=cal(a[i].x,a[j].x,a[i].y,a[j].y);
	  }
	floyd();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++){
	  	if(toget(i,j)&&f[i][j]>maxz[i]&&i!=j){
	  	  //cout<<i<<" "<<j<<endl;
	  	  maxz[i]=f[i][j];
	  }
    }
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	if(!toget(i,j))  continue;
	  	zd[i]=max(zd[i],max(maxz[i],maxz[j]));
	  	zd[j]=max(zd[j],max(maxz[i],maxz[j]));
	  }
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++){
	  	if(!toget(i,j)&&maxz[i]+maxz[j]+cal(a[i].x,a[j].x,a[i].y,a[j].y)<ans)
	  	  ans=max(maxz[i]+maxz[j]+cal(a[i].x,a[j].x,a[i].y,a[j].y),max(zd[i],zd[j]));
	  }
	printf("%.6f",ans);
	return 0; 
}