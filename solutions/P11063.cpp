#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int T,a,b,c,d;
struct node{
	int opt,k;
}ans[N];
int cnt;

void solve(){
	cnt=0;
	cin>>a>>b>>c>>d;
	if(a==c&&b==d){
		cout<<0<<endl;return;
	}
	if(a*b==c*d){
		ans[++cnt]={2,b};//k=y (a*b,1)->(c,d)
		ans[++cnt]={1,d};//(a*b/d,d)
	}
	else if(a*b<c*d){
		cout<<-1<<endl;return;
	}
	else{
	    int now=0;
		ans[++cnt]={2,b};//(a*b,1)->(c*d,1)
		int x=a*b,y=c*d;
		if(y==1){
			cout<<-1<<endl;return;
		}
		else{
			
			while(x!=y){
				int tmp=max(x/2+1,y);
				ans[++cnt]={now+1,tmp};
				x=x/tmp*tmp;
				now^=1;
			}
		}
		if(!now)  ans[++cnt]={now+1,d};
		else ans[++cnt]={now+1,c};
	}
	if(cnt>65){
		cout<<-1<<endl;
		return;
	}  
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)  cout<<ans[i].opt<<" "<<ans[i].k<<endl;
}
signed main(){
	cin>>T;
	while(T--)  solve();
	return 0;
}