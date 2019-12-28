#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define maxn 1000010
 
using namespace std;
const char *fi = "std.inp";
const char *fo = "std.out";
 
string a,b;
int F[maxn][4];
 
inline bool check(int x,int y){
    if (y==0) return (a[x-1]=='.' && b[x]=='.' && b[x-1]=='.');
    else if (y==1) return (a[x]=='.' && a[x-1]=='.' && b[x]=='.');
    else if (y==2) return (a[x]=='.' && b[x]=='.' && b[x-1]=='.');
    else return (a[x]=='.' && a[x-1]=='.' && b[x-1]=='.');
}
int main(){
    ios_base::sync_with_stdio(0);
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    cin.tie(0);
    int n;
    cin >> n;
    cin>>a;
    cin>>b;
 
    memset(F,0,sizeof(F));
    FOR(i,0,3) if (check(1,i)) F[1][i]=1;
    FOR(i,2,a.size()-1){
        FOR(j,0,3) {
            F[i][j]=F[i-1][j];
            if (check(i,j)){
                FOR(k,0,3) F[i][j]=max(F[i-2][k]+1,F[i][j]);
                if (j==1) F[i][j]=max(F[i-1][0]+1,F[i][j]);
                if (j==2) F[i][j]=max(F[i-1][3]+1,F[i][j]);
            }
        }
    }
 
    int res=0;
    FOR(i,0,3) res=max(res,F[a.size()-1][i]);
    cout << res;
    return 0;
}