#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n,s[N][2],t[N][2];
int b1[N],b2[N],sum[2][N][2];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        s[i][0]=c-48;
    }  
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        s[i][1]=c-48;
    }  
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        t[i][0]=c-48;
    }  
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        t[i][1]=c-48;
    }  


    int tmp=0;
    for(int i=1;i<=n;i++){
        if(!t[i][0])  continue;
        if(!t[i-1][0])  tmp++;
        //cout<<i<<" ccf "<<tmp<<endl;
        b1[i]=tmp;
        if(!s[i][0])  sum[0][tmp][0]++;
        else sum[0][tmp][1]++;
    }
  //  for(int i=1;i<=n;i++)  cout<<b1[i]<<" "<<sum[0][b1[i]][0]<<" "<<sum[0][b1[i]][1]<<endl;
    tmp=0;
    for(int i=1;i<=n;i++){
        if(!t[i][1])  continue;
        if(!t[i-1][1])  tmp++;
        //cout<<i<<" ccf "<<tmp<<endl;
        b2[i]=tmp;
        if(!s[i][1])  sum[1][tmp][0]++;
        else sum[1][tmp][1]++;
    }
  //  for(int i=1;i<=n;i++)  cout<<b2[i]<<" "<<sum[1][b2[i]][0]<<" "<<sum[1][b2[i]][1]<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!t[i][0]&&!t[i][1]){
            if(s[i][0]==s[i][1])  ans++;
        }
        else if(!t[i][0]&&t[i][1]){
            if(s[i][0]){
                if(sum[1][b2[i]][1]>0){
                    sum[1][b2[i]][1]--;ans++;//cout<<i<<" ";
                }
                else sum[1][b2[i]][0]--;
            }
            else{
                if(sum[1][b2[i]][0]>0){
                    sum[1][b2[i]][0]--;ans++;//cout<<i<<" ";
                }
                else sum[1][b2[i]][1]--;
            }
        }
        else if(t[i][0]&&!t[i][1]){
            if(s[i][1]){
                if(sum[0][b1[i]][1]>0){
                    sum[0][b1[i]][1]--;ans++;//cout<<i<<" ";
                }
                else sum[0][b1[i]][0]--;
            }
            else{
                if(sum[0][b1[i]][0]>0){
                    sum[0][b1[i]][0]--;ans++;//cout<<i<<" ";
                }
                else sum[0][b1[i]][1]--;
            }
        }
        else{
            if(sum[0][b1[i]][0]>0&&sum[1][b2[i]][0]>0){
                ans++;sum[0][b1[i]][0]--;sum[1][b2[i]][0]--;//cout<<i<<" ";
            }
            else if(sum[0][b1[i]][1]>0&&sum[1][b2[i]][1]>0){
                ans++;sum[0][b1[i]][1]--;sum[1][b2[i]][1]--;//cout<<i<<" ";
            }
            else{
                if(sum[0][b1[i]][0]>0){
                    sum[0][b1[i]][0]--;sum[1][b2[i]][1]--;
                }
                else{
                    sum[0][b1[i]][1]--;sum[1][b2[i]][0]--;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int _;cin>>_;
    while(_--)  solve();
    return 0;
}