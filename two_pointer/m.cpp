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
const int N = 2e5 + 9;

bool multiTestCases = false;

int n;
int a[N];
map<int,int> cnt;

void solve(){
    // Something goes here...
    cin>>n;
    int ans = 0;
    for(int i = 1; i<=n; i++) {
        cin>>a[i];
    }
    int j = 1;
    for(int i = 1; i<=n; i++){
        cnt[a[i]]++;
        while(cnt[a[i]] > 1){
            cnt[a[j]]--;
            j++;
        }
        ans = max(ans, i - j + 1);
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