/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 100005;

bool multiTestCases = false;

int n,m;
int p, l, q;
int pi[N];
bool vis[N];

int acs(int k){
    if(pi[k] == k) return k;
    return pi[k] = acs(pi[k]);
}

void join(int u, int v){
    int x = acs(u);
    int y = acs(v);

    if(x != y){
        pi[x] = y;
    }     
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++) {pi[i] = i;}
    for(int i = 1; i<=m; i++){
        cin>>p>>q>>l;
        if(p > q) swap(p,q);
        for(int j = 1; j <= l; j++){
            join(p+j-1,q+j-1);
        }
    }
    int ans = 1;
    for(int i = 1; i<=n; i++){
        int x = acs(i);
        if(vis[x] == false){
            vis[x] = true;
            ans = ans*2 % MOD;
        }
    }
    cout<<"lmao";
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}