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
using ull = unsigned int;
using ld = long double;

bool loopInput = false;
int MOD = 1e9 + 7;
int h, w;
char a[N][N];
int dp[N][N];

void solve(){
    // Something goes here...
    cin>>h>>w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin>>a[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i = 1; i<=h;i++){
        for(int j = 1; j<=w;j++){
            if(i == 1 && j == 1) continue;
            if(a[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    cout<<dp[h][w];
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