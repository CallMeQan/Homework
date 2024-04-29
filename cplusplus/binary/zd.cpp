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
int a[N], pos[N];
int b[N], c[N];
void solve(){
    b[0] = 0;
    c[0] = 0;
    // Something goes here...
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[i] = b[i-1] + a[i];
    }
    for(int i = 1; i<=n; i++){
        cin>>pos[i];
        c[i] = c[i-1] + a[i] * pos[i]; 
    }
    int ans = 1e18;
    for(int i = 1; i<=n; i++){
        int distanceTilEnd = c[n] - c[i];
        int cf = b[n] - b[i];
        int temp= pos[i] * b[i] - c[i] + distanceTilEnd - pos[i] * cf;
        ans = min(ans, temp); 
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