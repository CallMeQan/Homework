/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 5;

bool loopInput = false;

int n, k;
vector<int> g[N];

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1;i<=n; i++){
        int l, r;
        cin>>l>>r;
        g[l].pb(r);
    }
    int ans = 0;
    multiset<int> ms;
    for(int i = 1;i<=2e5; i++){
        while(ms.size()){
            auto it = ms.begin();
            if((int)(*it) >= i){
                break;
            }else{
                ms.erase(ms.find(*it));
            }
        }
        for(auto v: g[i]){
            ms.insert(v);
        }
        while(ms.size()>k){
            ans++;
            auto it = ms.end();
            it--;
            ms.erase(ms.find(*it));
        }
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
