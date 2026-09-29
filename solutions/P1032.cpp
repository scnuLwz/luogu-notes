#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
string a[6],b[6];
int cnt;
map<string,int> da,db;
queue<string> qa,qb;

int exten(queue<string> &q,map<string,int> &d1,map<string,int> &d2,string a[],string b[])
{
	string t=q.front();
	q.pop();
	for(int i=0;i<t.size();i++)
	  for(int j=0;j<cnt;j++)
	    if(t.substr(i,a[j].size())==a[j])
	    {
	    	string tt=t.substr(0,i)+b[j]+t.substr(i+a[j].size());
	    	if(d2.count(tt)) return 1+d1[t]+d2[tt];
	    	if(d1.count(tt)) continue;
	    	d1[tt]=d1[t]+1;
	    	q.push(tt);
		}
	return 11;
}
int bfs()
{
	while(!qa.empty()&&!qb.empty())
	{
		 int t;
		 if(qa.size()<=qb.size()) t=exten(qa,da,db,a,b);
		 else t=exten(qb,db,da,b,a);
		 if(t<=10) return t;
 	}
 	return 11;
}
int main()
{
    string A,B;
    cin>>A>>B;
    if(A==B){
        cout << 0;return 0;
    }
    while(cin>>a[cnt]>>b[cnt]) cnt++;
    qa.push(A),qb.push(B),da[A]=0,db[B]=0;
    int step=bfs();
    if(step>10) cout<<"NO ANSWER!";
    else cout<<step;
	return 0;
}