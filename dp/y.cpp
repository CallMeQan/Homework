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

int n;
int a[N][4], dp[N][4];

void solve(){
    // YOOOO, THIS IS MY FIRST DP PROBLEM I DONE WITHOUT ANY CLUE
    cin>>n;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=3; j++){
            cin>>a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2];
    dp[1][3] = a[1][3];

    for(int i = 2; i<=n; i++){
        dp[i][1] = max(dp[i-1][2] + a[i][1],dp[i-1][3] + a[i][1]);
        dp[i][2] = max(dp[i-1][1] + a[i][2],dp[i-1][3] + a[i][2]);
        dp[i][3] = max(dp[i-1][1] + a[i][3],dp[i-1][2] + a[i][3]);
    }
    int ans = max(dp[n][1], max(dp[n][2], dp[n][3]));
    cout<<ans;
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