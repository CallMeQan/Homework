/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 500006
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

int n,k;
int a[N];
int ST[4*N];

void build(int id, int l, int r){
    if (l == r){
        // Formular here...
        ST[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    
    // Checker here
    ST[id] = __gcd(ST[id*2], ST[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return a[u];
    if (u <= l && r <= v) return ST[id];
    
    int firstGet = get(2*id, l, (l+r)/2, u, v);
    int secondGet = get(2*id+1, (l+r)/2 + 1, r, u, v);
    // Remember to check condition...
    return __gcd(firstGet, secondGet);
}

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>a[i];
    build(1,1,n);
    int ans = 0;
    for(int i = k; i<=n; i++)
        ans = max(ans, get(1,1,n, i-k+1, i));
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