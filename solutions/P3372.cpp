#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 10;
int n, a[N], ans, t1[N], t2[N], m;  // t2=i*t1;

int low(int x) { return x & (-x); }
void add(int c[], int x, int y) {
    for (; x <= n; x += low(x)) c[x] += y;
}
int ser(int c[], int x) {
    int ans = 0;
    for (; x; x -= low(x)) ans += c[x];
    return ans;
}
int get(int l) { return (l + 1) * ser(t1, l) - ser(t2, l); }
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        t1[i] = a[i] - a[i - 1];
        t2[i] = t1[i] * i;
    }
    for (int i = 1; i <= n; i++) {
        if (i + low(i) > n)
            continue;
        t1[i + low(i)] += t1[i];
        t2[i + low(i)] += t2[i];
    }
    for (int i = 1; i <= m; i++) {
        int l, r, lx, c;
        cin >> lx;
        if (lx == 2) {
            cin >> l >> r;
            cout << get(r) - get(l - 1) << endl;
        } else {
            cin >> l >> r >> c;
            add(t1, l, c);
            add(t1, r + 1, -c);
            add(t2, l, l * c);
            add(t2, (r + 1), -(r + 1) * c);
        }
    }
    return 0;
}