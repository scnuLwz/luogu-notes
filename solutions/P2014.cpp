#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m, f[N][N], val[N], ans , sum;

vector<int> v[N], d;

void dfs(int p) {
    for (int i = 1; i <= m; i++) 
       f[p][i] = val[p];
    for (int k : v[p]) {
        dfs(k);

        for (int i = m; i >= 1; i--)
            for (int j = 0; j < i; j++) f[p][i] = max(f[p][i], f[p][i - j] + f[k][j]);
    }
}
int main() {
    cin >> n >> m;
    m++;
    for (int i = 1, x; i <= n; i++) {
        cin >> x >> val[i];
        v[x].push_back(i);
    }
    dfs(0);
    cout << f[0][m];
    return 0;
}