#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,a,b) for(int i=a;i<b;++i)

using namespace std;
const char *fi = "std.inp";
const char *fo = "std.out";

int n, k;
string A;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    cin >> n >> k;
    if (k == 1) {
        cout << "YES";
        return 0;
    }
    cin >> A;
    int cnt = 1;
    REP(i, 1, n) {
        if (A[i] == A[i-1]) {
            if ((++cnt) >= k) {
                cout << "YES";
                return 0;
            }
        } else 
            cnt = 1;
    }
    cout << "NO";
    return 0;
}