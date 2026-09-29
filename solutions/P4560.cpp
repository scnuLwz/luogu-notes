#include<bits/stdc++.h>
#define ls(p) p<<1
#define rs(p)  p<<1|1
#define INF 0x7fffffff 
using namespace std;

const int N = 2e6 + 10;

int n,m;
void write(int p);
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}return x*f;
} 

struct S_Tree{
	int maxn[N<<2],minn[N<<2];
	void fmax(int p,int k){
		if(maxn[p]<k)  maxn[p]=k;
		if(minn[p]<k)  minn[p]=k;
	}
	void fmin(int p,int k){
		if(maxn[p]>k)  maxn[p]=k;
		if(minn[p]>k)  minn[p]=k;
	}
	void push_down(int p){
		fmax(ls(p),maxn[p]);fmax(rs(p),maxn[p]);fmin(ls(p),minn[p]);fmin(rs(p),minn[p]);
		maxn[p]=0;minn[p]=INF;
	}
	void update(int p,int L,int R,int x,int y,int k,int tag){
		if(x<=L&&R<=y){
			if(!tag)  fmax(p,k);
			else fmin(p,k);
			return;
		}
		push_down(p);
		int mid=L+R>>1;
		if(x<=mid)  update(ls(p),L,mid,x,y,k,tag);
		if(y>mid)  update(rs(p),mid+1,R,x,y,k,tag); 
	}
	void ser(int p,int L,int R){
		if(L==R){
			printf("%d\n",maxn[p]);
			return;
		}
		int mid=L+R>>1;
		push_down(p);
		ser(ls(p),L,mid);
		ser(rs(p),mid+1,R);
	} 
}Tree;

int main(){
    n=read();m=read();
    for(int i=1;i<=ls(n);i++)  Tree.minn[i]=INF,Tree.maxn[i]=0;
    for(int i=1,t,L,R,h;i<=m;i++){
    	t=read();L=read();R=read();h=read();++L;++R; 
    	Tree.update(1,1,n,L,R,h,--t);
	}
	Tree.ser(1,1,n);
	return 0;
}

void write(int p){
	if(p>9)  write(p/10);
	putchar(p%10+'0');
}