/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 100006
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

bool loopInput = true;

int n, x;
int a[N], dp[N][206];

void solve(){
    // Something goes here...
    cin>>n>>x;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    dp[0][0] = 0;
    for(int i = 1; i<=n; i++){
        dp[i][0] = max(0LL, dp[i-1][0] + a[i]);
        dp[i][1] = max(0LL, max(dp[i-1][1], dp[i-1][0]) + a[i]*x);
        dp[i][2] = max(0LL, dp[i-1][2]+a[i]);
        dp[i][2] = max(dp[i][2],max(dp[i-1][1], dp[i-1][0])+a[i]*x);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }
    cout<<ans<<endl;
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