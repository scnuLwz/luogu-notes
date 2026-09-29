#include <bits/stdc++.h>

using namespace std;

const int N = 32010;

int m , n , f[N] , fw[N][3] , sw[N] , fc[N][3] , sc[N];
int main()
{
	cin >> m >> n;
	for(int i = 1 , v , p , q; i <= n ; i ++)
	{
		cin >> v >> p >> q;
		if(!q){
			sw[i]  = v;
			sc[i] = v * p;
		}
		else{
			fw[q][0] ++;
			fw[q][fw[q][0]] = v;
			fc[q][fw[q][0]] = v * p ;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sw[i] == 0||sc[i] == 0)  continue;
		for(int j=m;j>=sw[i];j--)
		{
			f[j] = max(f[j],f[j-sw[i]]+sc[i]);
			if(j>=sw[i]+fw[i][1])
			  f[j] = max(f[j],f[j-sw[i]-fw[i][1]]+fc[i][1]+sc[i]);
			if(j>=sw[i]+fw[i][2])
			  f[j] = max(f[j],f[j-sw[i]-fw[i][2]]+fc[i][2]+sc[i]);
			if(j>=sw[i]+fw[i][1]+fw[i][2])
			  f[j] = max(f[j],f[j-sw[i]-fw[i][1]-fw[i][2]]+fc[i][1]+fc[i][2]+sc[i]);
		}
	}
	cout<<f[m];
	return 0;
}