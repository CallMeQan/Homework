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

int n;
int S[11], dp[11][1005];

void solve(){
    // Something goes here...
    int sum = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>S[i];
        sum += S[i];
    }
    dp[0][0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= sum ; j++){
            for(int x = 1 ; x <= S[i] ; x++){
                if(j >= x)dp[i][j] += dp[i - 1][j - x];
            }
        }
    }
 
    long long res = 0 , value = -1;
    for(int i = 1 ; i <= sum ; i++){
        if(value < dp[n][i]){
            res = i;
            value = dp[n][i];
        }
    }
 
    cout << res;
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