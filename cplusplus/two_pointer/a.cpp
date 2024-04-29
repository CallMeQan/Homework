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

int n, m;
int a[N], b[N];

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++) cin>>a[i];
    for(int i = 1; i<=m; i++) cin>>b[i];
    int follow = 1;
    for(int i = 1; i<=n; i++){
        for (int j = follow; j <= m; j++)
        {
            if(b[j] <= a[i]){
                cout<<b[j]<<" ";
                follow++;
            }else if(b[j] > a[i]) break;
        }
        
        cout<<a[i]<<" ";
    }
    while(follow <= m){
        cout << b[follow] << " ";
        follow++;
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