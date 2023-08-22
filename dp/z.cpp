/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 105
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
int n, S;
int a[N], dp[N][1005];

void solve(){
    // Something goes here...
    cin>>n>>S;
    for(int i = 1; i <= n; i++) cin>>a[i];
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j = 0; j<= S; j++){
            dp[i][j] = dp[i-1][j];
            if(j-a[i] >= 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % MOD;
            }
        }
    }
    cout<<dp[n][S];
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