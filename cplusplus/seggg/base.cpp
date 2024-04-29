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
int a[4*N];

void update(int id, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r){
        // Formular here...
        
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id + 1, mid + 1, r, pos, val);
    
    // Checker here
    a[id] = max(a[2*id], a[2*id+1]);
}

int get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return -1e18;
    if (u <= l && r <= v) return a[id];
    
    int firstGet = get(2*id, l, (l+r)/2, u, v);
    int secondGet = get(2*id+1, (l+r)/2 + 1, r, u, v);
    // Remember to check condition...
    return max(firstGet, secondGet);
}

void solve(){
    // Something goes here...
    
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