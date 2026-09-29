#include<bits/stdc++.h>

using namespace std;


const int N = 1e6 + 10;

int cnt[N],n,a[N],T,b[N],c[N],si;
int w[N][2];
string solve(int lx){
	memset(w,0,sizeof w);
	deque<int> q1,q2,Q;si=0;memset(b,0,sizeof b);memset(c,0,sizeof c);
	string ans="L";if(lx)  ans="R";
	for(int i=1;i<=2*n;i++)  Q.push_back(a[i]);
	for(int i=1;i<=2*n;i++){
		if(!w[a[i]][0])  w[a[i]][0]=i;
		else w[a[i]][1]=i;
	}
	if(!lx){
		for(int i=2;i<w[a[1]][1];i++)  q1.push_back(a[i]);  
	    for(int i=2*n;i>=w[a[1]][1]+1;i--)  q2.push_back(a[i]);
	}
	else{
		for(int i=1;i<w[a[2*n]][0];i++)  q1.push_back(a[i]);
		for(int i=2*n-1;i>=w[a[2*n]][0]+1;i--)  q2.push_back(a[i]);
	}
	int cnt=1;bool fs=true;
	if(!lx)  b[cnt]=a[1];
	else b[cnt]=a[2*n];	
	while(cnt<n){	
		if(q1.size()>=2&&q1.front()==q1.back()){
			b[++cnt]=q1.front();ans+="L";q1.pop_front();q1.pop_back();continue;
		}  
		if(q1.size()>=1&&q2.size()>=1&&q1.front()==q2.back()){
			b[++cnt]=q1.front();ans+="L";q1.pop_front();q2.pop_back();continue;
		}
		if(q2.size()>=2&&q2.front()==q2.back()){
			b[++cnt]=q2.front();ans+="R";q2.pop_front();q2.pop_back();continue;
		}  
		if(q1.size()>=1&&q2.size()>=1&&q2.front()==q1.back()){
			b[++cnt]=q2.front();ans+="R";q2.pop_front();q1.pop_back();continue;
		}
		fs=false;break;
	}
//	for(int i=1;i<=n;i++)  cout<<b[i]<<" ";
	for(int i=0;i<ans.size();i++){
		if(ans[i]=='L')  Q.pop_front();
		else Q.pop_back(); 
	}
//	cout<<Q.front();
	while(Q.size()){
		c[++si]=Q.front();Q.pop_front();
	}
	int l=1,r=n;
    for(int i=n;i>=1;i--){
    	if(c[l]==b[i])  ans+="L",l++;
    	else if(c[r]==b[i])  ans+="R",r--;
	}
	if(!fs)  ans="no";
	return ans;
}
int main(){
	cin>>T;
	while(T--){
	    cin>>n;
	    for(int i=1;i<=2*n;i++)  cin>>a[i];
		if(solve(0)=="no"&&solve(1)=="no")  cout<<-1;
		else if(solve(0)!="no")  cout<<solve(0);
		else if(solve(1)!="no")  cout<<solve(1);
		puts("");
	}  
	return 0;
}
	