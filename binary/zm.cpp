/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 10000016
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

int n,m;
int a[N], pre[N];

void solve(){
    // Something goes here...
    pre[0] = 0;
    bool flagged = false;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        cout<<pre[i]<<" ";
        if(pre[i] % m == 0) {
            flagged = true;
            break;
        }
    }
    if(flagged) cout<<"YES";
    else cout<<"NO";
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