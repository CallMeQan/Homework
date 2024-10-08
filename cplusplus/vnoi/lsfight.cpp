/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
bool loopInput = false;

int n;

void solve(){
    cin>>n;
    bool a[n+1][n+1];
    int dp[n+1][n+1];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    // N - 1 lượt chơi
    for(int i = 1; i<=n-1; i++){

    }

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
