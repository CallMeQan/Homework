/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 3006
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

int n;
int a[N], dp[N][1003];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= 1001; j++){
            dp[i][j] = 1;
        }
    }

    for(int i = 1; i<=n; i++){
        for(int k = 1; k < i; k++){
            if(a[i]> a[k]) dp[i][a[i] - a[k]] = dp[k][a[i] - a[k]] + 1;
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= 1001; j++){
            ans = max(ans, dp[i][j]);
        }
    }
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