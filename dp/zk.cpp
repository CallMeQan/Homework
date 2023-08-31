/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 106
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

int n, w;
int a[N], b[N], dp[N][100005];

void solve(){
    cin>>n;
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> b[i] >> a[i];
        sum += a[i];
    }
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= sum ; j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<i; j++){
            dp[i][j] = dp[i-1][j];
            if(j-a[i]>=0) dp[i][j] = min(dp[i-1][j], dp[i-1][j-a[i]] + b[i]);
        }
    }
    int res = 0;
    for(int j = 0 ; j <= sum ; j++){
        if(dp[n][j] <= w)
            res = j;
    }            
    cout << res << endl;
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