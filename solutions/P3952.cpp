#include<bits/stdc++.h>

using namespace std;

const int N = 10100;

int tt , k , a[30] , R_ans , w;
string b,s,t,f;
string p;
char g[N];
int sta[N],top=1;
int get(string a,string b)
{
	
	// 1:可以进行(当前行是常数复杂度） 
	// 0：不可以进行(R_w=w）
	//2:当前行复杂度为O(N) 
	if(a=="n"&&b=="n")  return 1;
	if(b=="n"&&a!="n")  return 2;
	if(a=="n")  return 0;
	if((a[0]>='a'&&a[0]<='z')||(b[0]>='a'&&b[0]<='z'))  return 1;
	int g1=0,g2=0;
	for(int i=0;i<a.size();i++)  
	  if(isdigit(a[i]))
	    g1=g1*10+a[i]-48;
	for(int i=0;i<b.size();i++)  if(isdigit(b[i])) g2=g2*10+b[i]-48;
	if(g1<=g2)  return 1;
	if(g1>g2)  return 0;
}
int go_ans()
{
	int ans=-1;
	for(int i=1;i<top;i++)
	{
		if(sta[i] == 1)  continue;
		if(sta[i] == 0)  return ans;
		if(sta[i] == 2)  ans ++;
	}
	return ans;
}
bool chk_ans(int x,string s)
{
	int j = 0;
	for(int i=0;i<s.size();i++)  if(isdigit(s[i]))j=j*10+s[i]-48;
	if(x==j-1||x==-1&&j==1&&s.size()==4)
	  return true;
	return false;
}
bool chk_ERR(){
	for(int i=1;i<=26;i++)  if(a[i]>1)  return false;
	return true;
}
int main()
{
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	//cout<<OK("x","y");
	cin >> tt;
	while(tt--){
		memset(a,0,sizeof(a));
		bool can_f=false;
		int R_w = -1;
		top = 1;
		cin >> k;
		cin >> p;
		for(int i=1;i<=k;i++)
		{
			cin >> f;
			if(f[0]=='F')
			{
				cin >> b >> s >> t;	
				a[b[0]-'a'+1] ++;
                int w = get(s,t);
				sta[top] = w;g[top] = b[0];top++;
			}
            else{
            	if(!chk_ERR())
            	  can_f = true;
                if(top-1>=0&&g[top-1]-'a'+1>=1)
            	  a[g[top-1]-'a'+1]--;
            	R_w=max(R_w,go_ans());
            	if(top==0){
            		can_f=true;
				}
            	--top;
			}
		}
		if(can_f==true||top!=1){
			cout << "ERR" << endl;
			continue;
		}
		else{
			if(chk_ans(R_w,p))
			  cout << "Yes" << endl;
			else cout << "No"<< endl;
		}
	}
	return 0;
}