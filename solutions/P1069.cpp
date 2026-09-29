#include<bits/stdc++.h>
using namespace std;

int n,m1,m2,si,pri[10000],cnt,a[30001],b[30001],ans=1e8;//放指数 
bool v[30001];
void ai()
{
	for(int i=2;i<=30000;i++)
	  if(!v[i])
	    for(int j=2;j<=30000/i;j++)
	      v[i*j]=true;
	for(int i=2;i<=30000;i++)
	  if(!v[i])
	    pri[++cnt]=i;
}
int main()
{
	ai();
	cin>>n;
	cin>>m1>>m2;
	if(m1==1&&m2==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		while(m1%pri[i]==0)
		{
			a[i]++;
			m1/=pri[i];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>si;
		memset(b,0,sizeof(b));
		for(int j=1;j<=cnt;j++)
		{
			while(si%pri[j]==0)
			{
				b[j]++;
				si/=pri[j];
			}
		}
		int ma=-1;
		bool f=false;
		for(int j=1;j<=cnt;j++){
			if(a[j]>0){
				if(b[j]==0){
					f=true;
					break;
				}
				double t=a[j]*1.0*m2/b[j];
				t=ceil(t);
				//printf("%.6f\n",t);
				int p=t;
				//cout<<p<<" ";
				if(p>ma)  ma=p;
				//cout<<ma<<endl;
			}
		}
		//cout<<endl<<endl;
		if(!f)  ans=min(ans,ma);
	}
	if(ans!=1e8)
	  cout<<ans;
	else cout<<-1;
	return 0;
}