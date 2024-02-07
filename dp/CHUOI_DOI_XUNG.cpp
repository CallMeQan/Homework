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
const int N = 2009;

bool multiTestCases = false;

string str;
int dp[N][N];

void solve(){
    // Something goes here...
    cin>>str;
    str = '&' + str;
    int n = (int) str.size() - 1;
    for(int tmp = 1; tmp<=n; tmp++){
        for(int i = 1; i + tmp - 1 <=n; i++){
            int j = j + tmp - 1;
            if(j == i){
                dp[i][j] = 1;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                if(str[i] == str[j]){
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
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