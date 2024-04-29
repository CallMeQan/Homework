/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 2009;

bool multiTestCases = false;

string str;
int n;
int dp[N][N];

void solve(){
    // Something goes here...
    getline(cin, str);
    n = str.size();

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
