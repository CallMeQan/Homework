/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 3005
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

string s, t;
int dp[N][N];

void solve(){
    cin>>s>>t;
    s = '%' + s;
    t = '$' + t;
    dp[0][0] = 0;
    for(int i = 1; i < s.size(); i++){
        for(int j = 1; j<t.size(); j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
        }
    }
    cout<<dp[s.size()-1][t.size()-1]<<endl;
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