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
const int MOD = 1e9;
const int N = 1e6 + 9;

bool multiTestCases = false;

int a,b,m,n;

int power(int num, int pow){
    int res = 1;
    int power_of_x = num;
    while(pow){
        if(pow%2){
            res = res * power_of_x % MOD;
        }
        power_of_x = power_of_x * power_of_x % MOD;
        pow >>= 1;
    }
    return res;
}

void solve(){
    // Something goes here...
    cin >>a>>b>>n>>m;
    int res1 = power(a, n);
    int res2 = power(b, m);
    cout<<res1+res2<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
    return 0;
}