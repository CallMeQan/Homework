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

int n;
int a[N];
double cur_max = 0.0;
pii cur_pair;
vector<pii> same_pair;

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i<=n-1; i++){
        if(a[i] != a[i+1] && a[i+1] != 0 && cur_max < ((double)a[i] / (double)a[i+1])){
            cur_pair.fi = a[i];
            cur_pair.se = a[i+1];
            cur_max = ((double)a[i] / (double)a[i+1]);
        }
    }
    cout<<cur_pair.fi<<" "<<cur_pair.se;
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