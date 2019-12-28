#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define maxn 2010

typedef long long ll;
using namespace std;
const ll oo = 1e18;
const char *fi = "std.inp";
const char *fo = "std.out";

int n, k, A[maxn], B[maxn], posd;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n) cin >> A[i];
    FOR(i, 1, k) cin >> B[i];
    cin >> posd;
    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + k);
    ll res = oo;
    FOR(i, 1, k - n + 1) {
        ll tmp = 0;
        FOR(j, i, i + n - 1)
            tmp = max(tmp, (0LL + abs(B[j] - A[j - i + 1]) + abs(posd - B[j])));
        res = min(res, tmp);
    }
    cout << res;
    return 0;
}