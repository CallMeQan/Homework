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
using ld = long double;

bool loopInput = false;

int n,W;
int w[N], v[N], dp[N][100005];

void solve(){
    // Something goes here...
    cin>>n>>W;
    for(int i = 1; i<=n; i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= W ; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - w[i] >= 0)
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - w[i]] + v[i]);
        }
    }
 
    long long res = 0;
    for(int i = 1 ; i <= W ; i++)
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