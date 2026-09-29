#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int f[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
map<ll,bool> v;
ll s;
map<ll,int> d;
int bfs()
{
	queue<ll> q;
	q.push(s);
	d[s]=0;
    v[s]=true;
	while(!q.empty())
    {
    	ll t=q.front();
    	ll p=t;
    	q.pop();
    	if(t==123804765)  return d[t];
    	int a[3][3]={0},sx,sy;
    	for(int i=2;i>=0;i--)
    	  for(int j=2;j>=0;j--)
    	  {
		    a[i][j]=t%10,t/=10;
    	  	if(a[i][j]==0){
    	  		sx=i;sy=j;
    	  	}
    	  }
    	for(int i=0;i<4;i++){
    		int xx=f[i][0]+sx,yy=f[i][1]+sy;
    		if(xx<0||yy<0||xx>2||yy>2)  continue;
    		swap(a[xx][yy],a[sx][sy]);
    		int ns=0;
    		for(int i=0;i<3;i++)
    		  for(int j=0;j<3;j++)
    		    ns=ns*10+a[i][j];
    		if(!v[ns]){
    			q.push(ns);d[ns]=d[p]+1;v[ns]=true;
    		}
    		swap(a[xx][yy],a[sx][sy]);
    	}    
    	
    }
    return d[123804765];
}
int main()
{
	cin >> s;
	cout << bfs();
	return 0;
}