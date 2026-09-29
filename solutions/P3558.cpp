#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10 , mod = 100003;

int n,a[N],f[N][3],ans=1e9;
int z(int x){
	return x-1;
}
int main(){
	memset(f,0x3f,sizeof f);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    f[1][a[1]+1]=0;
    for(int i=2;i<=n;i++){
    	for(int j=0;j<3;j++){
    		if(!z(j)&&a[i]<z(j))  continue;
    		if(f[i-1][j]>1e9)  continue;
    	    //1.当前数比上一个数大 -1 0 -1 1
    	    if(a[i]>=z(j))  f[i][a[i]+1]=min(f[i][a[i]+1],f[i-1][j]);
			if(z(j)==-1){
				if(a[i]==0)  f[i][0]=min(f[i][0],f[i-1][j]+1);
				if(a[i]==1){
					f[i][1]=min(f[i][1],f[i-1][j]+1);
					f[i][0]=min(f[i][0],f[i-1][j]+2);
				}
			}
			//2.当前数比上一个数小 1 -1 
			if(z(j)==1){
				if(a[i]==0)  f[i][2]=min(f[i][2],f[i-1][j]+1);
				if(a[i]==-1)  f[i][2]=min(f[i][2],f[i-1][j]+2);
			}
		}
	}
//	for(int i=1;i<=n;++i,cout<<endl)
//	  for(int j=0;j<3;++j)
//	    cout<<f[i][j]<<" ";
	for(int i=0;i<3;++i)  ans=min(ans,f[n][i]);
	if(ans>1e8)  cout<<"BRAK";  
	else cout<<ans;
	return 0;
}