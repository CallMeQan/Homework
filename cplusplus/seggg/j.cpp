/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 300010
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

int n, m;
pair<int,int> ST[4*N];

void down(int id){
    int k = ST[id].se;
    if(k){
        ST[id].se = 0;
        ST[id*2].se += k;
        ST[id*2].fi += k;
        ST[id*2+1].se += k;
        ST[id*2+1].fi += k;
    }
}

void update(int id, int l, int r, int u, int v,int val){
    if (l > v || r < u) return;
    if (u<=l && r<=v){
        // Formular here...
        ST[id].fi += val;
        ST[id].se += val;
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update(2*id, l, mid, u, v, val);
    update(2*id + 1, mid + 1, r, u, v, val);
    
    // Checker here
    ST[id].fi = min(ST[2*id].fi, ST[2*id+1].fi);
}

int getLeft(int id, int l, int r, int u, int v, int k){
    if (l > v || r < u || ST[id].fi > k) return -1;
    if(l == r) return l;
    down(id);
    int mid = (l+r)/2;
    int left = getLeft(2*id, l, mid, u, v, k);
    if(left != -1){
        return left;
    }
    return getLeft(2*id+1, mid + 1, r, u, v, k);
}

int getRight(int id, int l, int r, int u, int v, int k){
    if (l > v || r < u || ST[id].fi > k) return -1;
    if(l == r) return l;
    down(id);
    int mid = (l+r)/2;
    int right = getRight(2*id+1, mid+1, r, u, v, k);
    if(right != -1){
        return right;
    }
    return getRight(2*id, l, mid, u, v, k);
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        int x;
        cin>>x;
        update(1,1,n,i,i,x);
    }
    while(m--){
        int type,add,k,l,r;
        cin>>type;
        if(type == 1){
            cin>>l>>r>>add;
            update(1,1,n,l,r,add);
        }else{
            cin>>l>>r>>k;
            cout<<getLeft(1,1,n,l,r,k)<<" "<<getRight(1,1,n,l,r,k)<<endl;
        }
    }
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