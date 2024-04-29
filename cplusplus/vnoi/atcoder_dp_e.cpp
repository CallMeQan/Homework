/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = false;

const int MAXN = 105 , MAXV = 1e5 + 5;
const int inf = 1e18;
 
int n , W;
int w[MAXN] , v[MAXN];
int dp[MAXN][MAXV];
 
void solve(){
    cin >> n >> W;
    int sumValue = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> w[i] >> v[i];
        sumValue += v[i];
    }
 
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= sumValue ; j++)
            dp[i][j] = inf;
 
    dp[0][0] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= sumValue ; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - v[i] >= 0)
                dp[i][j] = min(dp[i][j] , dp[i - 1][j - v[i]] + w[i]);
        }
    }
 
    int res = 0;
    for(int j = 0 ; j <= sumValue ; j++){
        if(dp[n][j] <= W)
            res = j;
    }            
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}