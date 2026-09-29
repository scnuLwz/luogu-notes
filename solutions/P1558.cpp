#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10 , M = 31;

int n,m,c;
int t[M][N<<2],ta[M][N<<2];

void push_d(int p,int l,int r,int i){
	int mid=(l+r)>>1;
	if(ta[i][p]!=-1){
		t[i][p<<1]=(mid-l+1)*ta[i][p];
		t[i][p<<1|1]=(r-mid)*ta[i][p];
		ta[i][p<<1]=ta[i][p<<1|1]=ta[i][p];
		ta[i][p]=-1;
	}
}
void add(int p,int l,int r,int x,int y,int c,int i){
	if(l>y||r<x)  return;
	if(l>=x&&r<=y){
		t[i][p]=(r-l+1)*c;
		ta[i][p]=c;
		return;
	}
	push_d(p,l,r,i);
	int mid=l+r>>1;
	if(x<=mid)  add(p<<1,l,mid,x,y,c,i);
	if(y>mid)  add(p<<1|1,mid+1,r,x,y,c,i);
	t[i][p]=t[i][p<<1]+t[i][p<<1|1];
	return;
}
int ser(int p,int l,int r,int x,int y,int c){
	if(l>y||r<x)  return 0;
	if(l>=x&&r<=y)  return t[c][p];
	else{
		int mid=(l+r)>>1;
		push_d(p,l,r,c);
    	return ser(p<<1,l,mid,x,y,c)+ser(p<<1|1,mid+1,r,x,y,c);
	}
}
int main()
{
	memset(ta,-1,sizeof ta);
    cin>>n>>c>>m;
    add(1,1,n,1,n,1,1);
    for(int i=1,x,y,cl;i<=m;i++){
    	char opt;
    	cin>>opt>>x>>y;
    	if(x>y)  swap(x,y);
    	if(opt=='C'){
    		cin>>cl;
    		for(int j=1;j<=c;j++)
    	    {
    	    	if(j==cl)  add(1,1,n,x,y,1,j);
    	    	else add(1,1,n,x,y,0,j);
			}
		}
		else{
			int ans=0;
			for(int j=1;j<=c;j++)
			  if(ser(1,1,n,x,y,j))
			    ++ans;
			cout<<ans<<endl;
		}
	}
    return 0;

}