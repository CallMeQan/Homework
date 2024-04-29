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
int ST[4*N];

void update(int id, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r){
        // Formular here...
        ST[id] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id + 1, mid + 1, r, pos, val);
    
    // Checker here
    ST[id] = min(ST[2*id], ST[2*id+1]);
}

int getLeft(int id, int l, int r, int u, int v, int k){
    if (l > v || r < u || ST[id] > k) return -1;
    if(l == r) return l;
    int mid = (l+r)/2;
    int left = getLeft(2*id, l, mid, u, v, k);
    if(left != -1){
        return left;
    }
    return getLeft(2*id+1, mid + 1, r, u, v, k);
}

int getRight(int id, int l, int r, int u, int v, int k){
    if (l > v || r < u || ST[id] > k) return -1;
    if(l == r) return l;
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
        update(1,1,n,i,x);
    }
    while(m--){
        int type,pos,k,l,r;
        cin>>type;
        if(type == 1){
            cin>>pos>>k;
            update(1,1,n,pos,k);
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