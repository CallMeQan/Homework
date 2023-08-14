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
int a[N];
int mod = 1e9+7;
void solve(){
    // Something goes here...
    cin>>n;
    a[1] = 1;
    a[2] = 1;
    for(int i = 3; i<=n; i++){
        a[i] = (a[i-1] + a[i-2]) % mod;
    }
    cout<<a[n];
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