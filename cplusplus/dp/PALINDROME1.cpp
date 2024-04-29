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
const int N = 508;

bool multiTestCases = false;

string str;
int n;
int dp[N][N];

void solve(){
    // Something goes here...
    cin>>str;
    str = '*' + str;
    int n = str.size() - 1;
    for(int l = 1; l <= n; l++){
        for(int r = n; r>=1; r--){
            if(l == r){
                dp[r][l] = 0;
                continue;
            }
            if(str[l] == str[r]){
                dp[r][l] = dp[r+1][l-1];
                continue;
            }
            dp[r][l] = min(dp[r][l-1] + 1, dp[r+1][l] + 1);
        }
    }
    cout<<dp[n][1]<<endl;
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