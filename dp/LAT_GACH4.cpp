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
using ld = long double;

bool loopInput = false;
int MOD = 998244353;
int n;
int a[N], w[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n;
    w[0] = 1;
    w[1] = 1;
    w[2] = 5;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 12;
    for(int i = 3; i<= n; i++){
        w[i] = (w[i-1] + 4*w[i-2] + 2*w[i-3]) % MOD;
    }
    for(int i = 3; i<= n; i++){
        dp[i] = (dp[i-1] + 4*dp[i-2] + 12*w[i-2] + 2*dp[i-3] + 12*w[i-3]) % MOD;
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