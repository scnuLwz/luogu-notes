# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=510;

int a[N][N],c,n;
bool v[N][N]={false};
ll f[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(ll x,ll y,ll h)
{
	c++;
	v[x][y]=true;
	for(ll i=0;i<4;i++)
	{
		ll xx=f[i][0]+x,yy=f[i][1]+y;
		if(xx<1||yy<1||xx>n||yy>n||v[xx][yy]||abs(a[xx][yy]-a[x][y])>h)
		  continue;
		dfs(xx,yy,h);
	}
}
bool chk(ll x)
{
	memset(v,false,sizeof(v));
	for(ll i=1;i<=n;i++)
	  for(ll j=1;j<=n;j++)
	  {
	  	if(!v[i][j]){
	  		c=0;dfs(i,j,x);
	  	}
	  	if(c>=(n*n+1)/2)  return true;
	  }
	return false;
}
int main()
{
	cin >> n;
	for (ll i=1;i<=n;i++)
	  for(ll j=1;j<=n;j++)
	    cin >> a[i][j];
	ll z=0,y=1e14;
	while(z<y)
	{
		ll mid=(z+y)>>1;
		if(chk(mid))  y=mid;
		else z=mid+1;
	}
	cout << y;
	return 0;
}
