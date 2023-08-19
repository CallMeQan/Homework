/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n, mod = 1e9 +7;
int a[N], dp[N], g[N];

void solve(){
    cin>>n;
    cout<<dp[n]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    g[0] = 1;
    g[1] = 3;
    g[2] = 10;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    // Something goes here...
    for(int i = 3; i <= N; i++){
        dp[i] = (2*dp[i-1] + 3*dp[i-2] + 2*g[i-3]) % mod;
        g[i] = (g[i-1] + dp[i])%mod;
    }
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}