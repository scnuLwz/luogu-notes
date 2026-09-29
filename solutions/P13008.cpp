#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10 , INF = 2e9;

int a[40],f[40][2],n;

inline int R(){
    int F=1,x=0;char c;c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  F=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-48;c=getchar();
    }
    return x*F;
}

inline void solve(){
    memset(f,0,sizeof f);memset(a,0,sizeof a);
    int st,ed;st=R();ed=R();n=R();int x=abs(st-ed);
    for(int i=0;i<=n;++i){
        a[i]=R();
        if(i)  a[i]=min(a[i],a[i-1]*2);
    }
    for(int i=n+1;i<=32;i++)  a[i]=a[i-1]*2;
    f[0][1]=INF;//f i j 表示前i位中第i位被变成j的最小代价
    for(int i=1;i<=32;i++){
        int m=(x>>(i-1))&1;
        if(!m){
            f[i][0]=min(f[i-1][0],f[i-1][1]+a[i-1]);
            f[i][1]=min(f[i-1][0]+2*a[i-1],f[i-1][1]+a[i-1]);
        }
        else{
            f[i][0]=min(f[i-1][0]+a[i-1],f[i-1][1]+2*a[i-1]);
            f[i][1]=min(f[i-1][1],f[i-1][0]+a[i-1]);
        }
    }
    cout<<f[32][0]<<endl;
}
signed main(){
    int __;cin>>__;
    while(__--)  solve();
    return 0;
}