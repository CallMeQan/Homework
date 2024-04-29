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
using ld = long double;

bool loopInput = false;

int n,m;
int a[N];
int non_possible;
bool dp[10006][10006];

void solve(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        a[i] %= m;
    }
    if(n >= m){
        cout<<"YES"<<endl;
        return;
    }
    dp[1][a[1]] = true;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<m;j++){
            dp[i][j] = dp[i-1][j] | dp[i - 1][(j - a[i] + m) % m];
        }
        dp[i][a[i]] = true;
    }
    if(dp[n][0] == true)
        cout << "YES" << endl;
    else cout << "NO" << endl;
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