#include <bits/stdc++.h>

using namespace std;
bool suc = false, p;
int T;
int a[10][10];
const int m[7][7] = { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 1 }, { 0, 0, 1, 1, 1, 1 },
                      { 0, 0, 0, 2, 1, 1 }, { 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0 } };
int f() {
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (a[i][j] != m[i][j])
                cnt++;
    return cnt;
}
const int dx[] = { 0, 1, 1, -1, -1, 2, 2, -2, -2 };
const int dy[] = { 0, 2, -2, 2, -2, 1, -1, 1, -1 };
bool v[10][10];
bool chk(int xx, int yy) { return xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5; }
inline void A_star(int s,int depth,int x,int y){
    if(s==depth){
        if(!f())  suc=true;  
        return;
    }
    if(suc==true)  return;
    for(int i=1;i<=8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(!chk(xx,yy))continue;
        swap(a[x][y],a[xx][yy]);
        if(f()+s<=depth)
            A_star(s+1,depth,xx,yy);
        swap(a[x][y],a[xx][yy]);//回溯
    }
}
int main() {
    scanf("%d", &T);
    while (T--) {
        int bx, by;
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++) {
                char x;
                cin >> x;
                if (x == '1')
                    a[i][j] = 1;
                if (x == '0')
                    a[i][j] = 0;
                if (x == '*') {
                    a[i][j] = 2;
                    bx = i;
                    by = j;
                }
            }
        suc = false;
        p = false;
        int i;
        for (i = 1; i <= 15; i++) {
            A_star(0, i, bx, by);
            if (suc == true) {
                printf("%d\n", i);
                i = 20;
            }
        }
        if (suc == false)
            puts("-1");
    }
    return 0;
}