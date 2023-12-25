/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1006
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
int a[N], b[N], dp[N][N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i]>>b[i];
    }
    dp[0][0] = 0;
    for(int i = 1 ; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i]+b[j] >= 0){
                dp[i][j] = dp[i-1][j-1]+1;
            }
        }
    }
    cout<<dp[n][n]<<endl;
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