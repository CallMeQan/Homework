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
const int N = 2009;

bool multiTestCases = false;

int n, k;
int a[N];

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    pii ans = {1e9,1e9};
    for(int i = 1; i<=n; i++){
        int tmp = a[i];
        for(int j = i+1; j<=n; j++){
            tmp += a[j];
            if(tmp == k){
                if((j-i+1) < ans.se){
                    ans.fi = i;
                    ans.se = j - i + 1;
                }
                break;
            }else if(tmp > k) break;
        }
    }
    if(ans.fi == 1e9){
        cout<<0<<endl;
    }else cout<<ans.fi<<" "<<ans.se<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TDOAN.INP", "r", stdin);
    freopen("TDOAN.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
