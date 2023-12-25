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
const int N = 1e5 + 9;

bool multiTestCases = false;

int n,m;
int a[N], h[N];
bool check[N] = {false};

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){cin>>a[i];}
    for(int i = 1; i<=n; i++) cin>>h[i];
    int ans = 0;
    int j = 1;
    int sum = 0;
    for(int i = 1; i<=n; i++){
        if(h[i-1] % h[i] == 0){
            sum+=a[i];
        }else {j=i;sum = a[i];}
        while(sum>m){
            sum -= a[j];
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