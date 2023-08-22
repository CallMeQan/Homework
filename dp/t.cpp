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

int MOD = 1e9 + 7;
int n,k;
int dp[N];

void solve(){
    cin>>n>>k;
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        dp[i] = (2 * dp[i - 1]) % MOD;
        if(i - k - 1 >= 0)
            dp[i] = ((int)dp[i] - dp[i - k - 1] + (int)MOD * MOD) % MOD;
        else if(i - k == 0)
            dp[i] = ((int)dp[i] - 1 + (int)MOD * MOD) % MOD;
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