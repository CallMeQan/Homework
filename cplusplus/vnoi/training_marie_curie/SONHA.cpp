/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = false;

int n;
int a[N];

void solve(){
    // Something goes here...
    cin>>n;
    int ans = 1;
    for(int i = 1; i<=n; i++){
        int tmp = i;
        while(tmp > 0){
            int tmp2 = tmp % 10;
            if(tmp2) ans++;
            else if(tmp2 == 0 && tmp >= 10) {
                ans++;
            }tmp /= 10;
        }
    }
    cout<< 1000000000 % 10 <<endl;
    cout<<ans<<endl;
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