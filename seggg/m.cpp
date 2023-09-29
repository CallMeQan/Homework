/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 705
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
int a[N][N];
int ST[4*N];
array<pair<int,int>> b[N*N];
int f[N*N], g[N*N];
int ans[2*N];

void update(int id, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r){
        // Formular here...
        ST[id] = max(ST[id], val);
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id + 1, mid + 1, r, pos, val);
    
    // Checker here
    ST[id] = max(ST[2*id], ST[2*id+1]);
}

void update_mark(int id, int l, int r, int i, int val){
    if(i>r || i<l) return;
    if( l == r) {
        ST[id] = val;
        return;
    }

    int mid = (l+r)/2;
    update_mark(id*2,l,mid,i,val);
    update_mark(id*2+1,mid+1,r,i,val);

    ST[id] = max(ST[id*2], ST[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return ST[id];
    
    int mid = (l+r)/2;
    int firstGet = get(2*id, l, mid, u, v);
    int secondGet = get(2*id+1, mid + 1, r, u, v);
    // Remember to check condition...
    return max(firstGet, secondGet);
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
            b[a[i][j]].push_back(pair<int,int>(i,j));
        }
    }

    for(int x = 1; x<=n*n; x++){
        sort(b[x].begin(), b[x].end());
        for(int i = 0; i<b[x].size(); i++){
            f[i] = g[i] = 0;
        }

        for(int i = 0; i<b[x].size(); i++){
            f[i] = 1 + get(1,1,n,1,b[x][i].se);
            update(1,1,n,b[x][i].se,f[i]);
        }

        for(int i = 0; i<b[x].size();i++){
            update_mark(1,1,n,b[x][i].se, 0);
        }

        for(int i = b[x].size() - 1; i>=0; i--){
            g[i] = 1+get(1,1,n,b[x][i].se, n);
            update(1,1,n,b[x][i].se, g[i]);
        }

        for(int i = 0; i<b[x].size(); i++){
            update_mark(1,1,n,b[x][i].se, 0);
        }

        for(int i = 0; i<b[x].size(); i++){
            ans[f[i] + g[i] - 1]++;
        }
    }
    for(int i = 1; i<=2*n-1;i++){
        cout<<ans[i]<<endl;
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