#include<bits/stdc++.h>
#define rep(i,x,y)  for(int i=x;i<=y;i++)
using namespace std;

const int N = 1e6 + 10;

int n,a[N],cnt,last=1;

struct node{
	int st,ed,x;
};
queue<node> q,h;

bool v[N];
int main(){
	cin>>n;
	rep(i,1,n)  cin>>a[i];
	a[n+1]=-1;
	rep(i,2,n+1){
		if(a[i]!=a[i-1]){
			q.push({last,i-1,a[i-1]});
			last=i;
		}
	}int cnt=n;
	while(cnt){
		while(q.size()){
		    //cout<<"ccf";
			node t=q.front();q.pop();
			while(v[t.st]&&t.st<=t.ed)  t.st++;
			if(t.st>t.ed)  continue;
			v[t.st]=true;cout<<t.st<<" ";cnt--;
			if(t.st==t.ed)  continue;
			t.st++;
			h.push(t);
		}
		while(h.size()){
			node t=h.front();
			h.pop();
			while(h.size()){
				node f=h.front();
				if(f.x==t.x){
					t.ed=f.ed;
					h.pop();
				}else break;
			}
			q.push(t);
		}
		cout<<endl;
	}
    return 0;
}