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

int n, mod = 998244353;
int a[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    for(int i = 4; i<=n; i++){
        dp[i] = (dp[i-1] + 4*dp[i-2] + 2*dp[i-3]) % mod;
    }
    cout<<dp[n];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}