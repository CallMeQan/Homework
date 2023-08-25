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
int a[N], b[N], c[N];

void solve(){
    // Something goes here...
    cin>>n;
    b[0] = 0;
    c[n+1] = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        b[i] = b[i-1];
        if(a[i] == 2) b[i]++;
    }
    for(int i = n; i > 0; i--){
        c[i] = c[i+1];
        if(a[i] == 1) c[i]++;
    }
    int ans = 1e9;
    for(int i = 0; i <= n; i++){
        ans = min(ans, b[i] + c[i+1]);
    }
    cout<<ans;
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