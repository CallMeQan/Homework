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
const int N = 2e6 + 9;

bool multiTestCases = false;
int ans = 1e9;
int n, S;
int a[N];

void solve(){
    // Something goes here...
    cin>>n>>S;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        if(i!= n){
            a[i+n] = a[i];
        }
    }
    int m = 2*n - 1;
    int r = 1, sum = 0;
    for(int l = 1; l<=n; l++){
        while(r<=m && sum + a[r] < S){
            sum+=a[r];
            r++;
        }
        if(r-l+1 <= n){
            ans = min(ans, r - l +1);
        }
        sum -= a[l]; 
    }
    if(ans == 1e9){
        cout<<-1;
        return;
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