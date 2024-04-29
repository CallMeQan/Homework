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
const int N = 1e6 + 9;

bool multiTestCases = false;

int n,q;
int a[N];

int access(int u){
    if(a[u] == u) return u;
    return access(a[u]);
}

void join(int u, int v)
{
    int x = access(u);
    int y = access(v);
    if(x != y) a[x] = y;
}

void solve(){
    // Something goes here...
    cin>>n>>q;
    for(int i = 1; i<=n; i++)a[i] = i;
    for(int i = 1; i<=q;i++){
        char c;
        int u, v;
        cin>>c>>u>>v;
        if(c == '?'){
            if(access(u) == access(v)){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }else{
            join(u,v);  
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