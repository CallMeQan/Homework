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
const int N = 5e5 + 9;

bool multiTestCases = false;

int n, q;
pii a[N];
// {connected, total_connected}

int acs(int k)
{
    if(a[k].fi == k) return k;
    return a[k].fi = acs(a[k].fi);
}
 
void join(int u, int v)
{
    int x = acs(u);
    int y = acs(v);
 
    if(x!=y)
    {
        a[y].fi = x;
       // sz[x] += sz[y];
        a[x].se += a[y].se;
    }
}

void solve(){
    // Something goes here...
    cin>>n>>q;
    for(int i = 1; i<=n; i++) {
        a[i].fi = i;
        a[i].se = 1;
    }
    for(int i = 1; i<=q; i++) {
        char c;
        int u,v;
        cin>>c;
        if(c == '+'){
            cin>>u>>v;
            join(u,v);
        }else{
            cin>>u;
            int k = acs(u);
            cout<<a[k].se<<endl;
        }
    }
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