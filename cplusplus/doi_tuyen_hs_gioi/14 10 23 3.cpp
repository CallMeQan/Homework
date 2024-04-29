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
const int N = 1e6 + 9;

bool multiTestCases = false;

int ans, x, y;
int a[N];
int ans = 1;
void solve(){
    // Something goes here...
    cin >> x >> y;
    int power_of_x = x;
    while(y){
        if(y % 2){
            ans = ans * power_of_x % MOD;
        }
        power_of_x = power_of_x * power_of_x % MOD;
        y >>= 1;
    }
    cout << ans;
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