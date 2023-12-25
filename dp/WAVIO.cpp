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
const int N = 1005;

bool multiTestCases = false;

int n;
int a[N], dpTang[N], dpGiam[N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++) {
        dpGiam[i] = 1;
        dpTang[i] = 1;
        cin>>a[i];
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<i; j++){
            if(a[j] < a[i]){
                dpTang[i] = max(dpTang[i], dpTang[j] + 1);
            }
        }
    }
    reverse(a+1, a+1+n);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<i; j++){
            if(a[j] < a[i]){
                dpGiam[i] = max(dpGiam[i], dpGiam[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, min(dpTang[i], dpGiam[n-i+1]) * 2 - 1);
    }
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