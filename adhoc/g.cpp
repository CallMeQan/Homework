/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 100006
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

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    int ans = 0;
    sort(a + 1, a + n + 1);
    for(int i = n-1; i>n/3; i-=2){
        ans += a[i];
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