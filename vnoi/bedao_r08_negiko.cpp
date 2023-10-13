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
bool multiTestCases = false;

const int MAXN = 1e3 + 5;
const int inf = 1e18;
const int MOD = 1e9 + 9;
 
int n , m , k;
int a[MAXN] , b[MAXN];
int dp[MAXN][MAXN][15];
 
 
void solve(){
 
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= m ; i++) cin >> b[i];
 
    sort(a + 1 , a + 1 + n);sort(b + 1 , b + 1 + m);
 
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= m ; j++) dp[i][j][0] = 1;
 
    for(int t = 1 ; t <= k ; t++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                dp[i][j][t] = (dp[i][j - 1][t] + dp[i - 1][j][t]) % MOD;
                dp[i][j][t] = (dp[i][j][t] - dp[i - 1][j - 1][t] + MOD * MOD) % MOD;
                if(a[i] > b[j])dp[i][j][t] = (dp[i][j][t] + dp[i - 1][j - 1][t - 1]) % MOD;
            }
        }
    }
 
    cout << dp[n][m][k] << endl;
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