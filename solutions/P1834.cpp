#include<bits/stdc++.h>

using namespace std;

int a[10];
string ans,s[10];
bool v[10],g[10];

void dfs(int k){
	if(k==7){
		if(a[7]==24)
		{
			if(ans == "") ans = s[7];
			ans=min(ans,s[7]);
		}
		return;
	}
	for(int i=1;i<=k;i++)
	{
		if(!v[i]){
			v[i]=true;
			for(int j=1;j<=k;j++)
			{
				if(i==j)  continue;
				if(!v[j]){
					v[j]=true;
					a[k+1]=a[i]+a[j];
					s[k+1]="("+s[i]+"+"+s[j]+")";
					dfs(k+1);
					a[k+1]=a[i]-a[j];
					s[k+1]="("+s[i]+"-"+s[j]+")";
					dfs(k+1);
					a[k+1]=a[i]*a[j];
					s[k+1]="("+s[i]+"*"+s[j]+")";
					dfs(k+1);
					if(a[j] != 0)
		             if(a[i]%a[j]==0){
			             s[k+1]="("+s[i]+"/"+s[j]+")";
			             a[k+1]=a[i]/a[j];
			             dfs(k+1);
		            }
					v[j]=false;
				}
			}
			v[i]=false;
		}
	}
}
int main()
{
	for(int i=1;i<=4;i++)  cin >> a[i];
	for(int i=1;i<=4;i++)  s[i]+=char(a[i]+48);
	dfs(4);
	cout << ans;
	return 0;
}
