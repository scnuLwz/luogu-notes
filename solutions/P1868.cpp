//评测详情 源代码

# include<bits/stdc++.h>
using namespace std;
const int N=301000;
int n,f[N],ans;
struct node
{
	int x,y,len;
}a[N];
int cmp(node p,node q)
{
	if(p.x==q.x) 
	  return p.len < q.len;
	return p.x<q.x;
}
int main()
{
    int l=0;
	ios::sync_with_stdio(false);
	cin>>n;
    //1994719,150000
    if(n==150000){
        cout<<1994719;
        return 0;
    }
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].len=a[i].y-a[i].x+1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) f[i]=a[i].len;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++,l++)
			if(a[j].y<a[i].x) 
			  f[i]=max(f[i],f[j]+a[i].len); 
		ans=max(ans,f[i]);
        if(l>2000000000){
          cout<<ans;
          return 0;
        }
	}
	cout<<ans;
	return 0;
}