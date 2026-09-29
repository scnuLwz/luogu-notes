#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int T,n,cnt;
int a[N],b[N],e[N],f[N];
map<int,int> id;
vector<int> h;
map<int,bool> v;
void get(){
    v.clear();
    for(int i=0,j=1;i<n*2;i++)  
    {
        if(v[h[i]])  continue;
        v[h[i]]=true;id[h[i]]=i+1;
    }
    for(int i=1;i<=n;i++)
      a[i]=id[a[i]],b[i]=id[b[i]];

}
int find(int x){
    if(f[x]!=x)  return f[x]=find(f[x]);
    return x;
}
bool hb(){
    for(int i=1;i<=n*2;i++)  f[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(e[i]==1)
        {
            int p=find(a[i]),q=find(b[i]);
            if(p!=q){
              f[p]=q;
            }
            
        }
    }
    for(int i=1;i<=n;i++)
      if(e[i]==0&&find(a[i])==find(b[i]))
        return false;
    return true;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		h.clear();
		cnt=0;
		for(int i=1,p,q;i<=n;i++){
			cin>>p>>q>>e[i];
			a[++cnt]=p;b[cnt]=q;h.push_back(p);h.push_back(q);
		}
		sort(h.begin(),h.end());
        h.erase(unique(h.begin(),h.end()),h.end());
		get();
		if(hb()){
		    cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}