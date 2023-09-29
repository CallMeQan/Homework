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
const long long inf = 1e18;
bool loopInput = true;

int n, k, l, r;
int ST[4*N], lazy[N*4];

void down(int id) {
    long long k = lazy[id];
    if (k) {
        lazy[id] = 0;
        lazy[id * 2] += k;
        ST[id * 2] += k;
        lazy[id * 2 + 1] += k;
        ST[id * 2 + 1] += k;
    }
}
 
void update(int id, int l, int r, int u, int v, int val) {
    if (u > r || v < l) {
        return;
    }
 
    if (u <= l && r <= v) {
        ST[id] += val;
        lazy[id] += val;
        return;
    }
 
    down(id);
 
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
 
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}
 
long long get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) {
        return -inf;
    }
 
    if (u <= l && r <= v) {
        return ST[id];
    }
 
    down(id);
 
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}


void solve(){
    int type;
    cin>>type;
    if(type==0){
        cin>>l>>r>>k;
        update(1,1,n,l,r,k);
    }else if(type==1){
        cin>>l>>r;
        cout<<get(1,1,n,l,r)<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >>n>>t;
        while (t--) solve();
    } else solve();
}