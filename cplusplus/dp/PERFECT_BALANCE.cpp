/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 5006
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

int n, k, x;
int a[N], dp[N][N];

void solve(){
    // Something goes here...
    cin>>n>>k>>x;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    dp[0][0] = 0;
    dp[0][0] = 0;
    for(int t = 1 ; t <= k ; t++){
        int opt = 1;
        for(int i = 1 ; i <= n ; i++){
            while(a[i] - a[opt] > x)
                opt++;
 
            dp[i][t] = max(dp[i - 1][t] , dp[opt - 1][t - 1] + (i - opt + 1));
        }
    }
    int res = 0;
    for(int i = 1 ; i <= k ; i++)
        res = max(res , dp[n][i]);
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