#include<bits/stdc++.h>

using namespace std;

const int N = 60;
int n,c,f[N][N][2],s[N];
int a[N],b[N];

int cal(int x,int y,int qx,int qy)
{
	int powr=s[n]-(s[y]-s[x-1]);
	return powr*abs(a[qx]-a[qy]);
}
int main(){
	memset(f,127,sizeof f);
    cin>>n>>c;
    for(int i=1;i<=n;i++)
      cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)  s[i]=s[i-1]+b[i];
    f[c][c][0]=f[c][c][1]=0;
    for(int len=2;len<=n;len++){
    	for(int i=1;i<=n-len+1;i++)
    	{
    		int j=i+len-1;
    		f[i][j][0]=min(f[i+1][j][0]+cal(i+1,j,i,i+1),f[i+1][j][1]+cal(i+1,j,i,j));//在i号点 
    		f[i][j][1]=min(f[i][j-1][1]+cal(i,j-1,j-1,j),f[i][j-1][0]+cal(i,j-1,i,j));
    	}
    }
    cout<<min(f[1][n][1],f[1][n][0]);
	return 0;
} 