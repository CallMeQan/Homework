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

int n, k;
int a[N];

void solve(){
    // (a1 + a2 + a3 + ...) * x <=k
    cin>>n>>k;
    int total = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        total += a[i];
    }
    if(total>k) cout<<-1;
    else cout<<k/total;
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