#include <iostream>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <functional>
#include <string>
 
#define maxn 300010
#define FOR(i,x,y)   for (int i=x;i<=y;++i)
#define FORD(i,x,y)  for (int i=x;i>=y;--i)
 
typedef long long ll;
using namespace std;
const char *fi = "std.inp";
const char *fo = "std.out";
 
int n,A[2][maxn];
ll P[2][maxn],sum[maxn],res,S[maxn];
 
int main(){
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    scanf("%d",&n);
    FOR(i,0,1) FOR(j,1,n) scanf("%d",&A[i][j]);
 
    sum[n+1]=0;
    FORD(i,n,1) sum[i]=sum[i+1]+A[0][i]+A[1][i];
 
    P[0][n+1]=0;
    FORD(i,n,1) P[0][i]=P[0][i+1]+sum[i+1]+2LL*A[0][i]*(n-i+1)+A[1][i];
 
    P[1][n+1]=0;
    FORD(i,n,1) P[1][i]=P[1][i+1]+sum[i+1]+2LL*A[1][i]*(n-i+1)+A[0][i];
 
    S[1]=A[1][1];
 
    res=P[1][1]-sum[1];
    S[0]=0;
    FOR(i,1,n){
        S[i]=S[i-1]+(sum[i]-sum[i+1])*(i-1)*2;
        if (i%2 == 0) {
            S[i]+=A[0][i];
            res=max(res,S[i]+P[1][i+1]+sum[i+1]*((i<<1)-1));
        }
        else {
            S[i]+=A[1][i];
            res=max(res,S[i]+P[0][i+1]+sum[i+1]*((i<<1)-1));
        }
//        cout<<i<<' '<<S[i]<<' '<<res<<' '<<P[1][i+1]<<endl;
    }
 
    printf("%lld",res);
    return 0;
}