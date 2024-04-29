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
const int N = 1e5 + 9;

bool multiTestCases = false;

int n;
int dp[N];

void solve(){
    // Something goes here...
    /*
        Đi học muộn 2 ngày liên tiếp hoặc nghỉ 2 ngày bất kỳ = BAN
        dp[i]: chứa số khả năng lách trong i ngày

        2
        
    */
    cin>>n;
    dp[0] = 0;
    dp[1] = 3;
    for(int i = 2; i<=n; i++){

    }
    cout<<dp[n];
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