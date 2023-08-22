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
int MOD = 1e9+7;
int n;
int a[105];
bool dp[105][1005];

void solve(){
    cin>>n;
    int S = 0;
    for(int i = 1; i<=n; i++) {cin>>a[i]; S+= a[i];}
    dp[0][0] = true;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= S ; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - a[i] >= 0){
                if(dp[i - 1][j - a[i]] == true)
                    dp[i][j] = true;
            }
        }
    }
 
    int res = -1e9;
    for(int j = 0 ; j <= S ; j++)
        if(dp[n][j] == true)
            res = max(res , j*(S-j));
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