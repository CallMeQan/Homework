/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N = 105;

bool multiTestCases = false;

int n, m;
int C[N][N], dp[N][N];
/*
    mỗi hàng là kênh chuyển
    mỗi cột là gói tin
*/

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin>>C[i][j];
        }
    }
    vector<int> a;
    for(int j = 1; j <=m; j++){
        //J là kênh
        for(int i = 1; i<=n; i++){

        }
    }
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
