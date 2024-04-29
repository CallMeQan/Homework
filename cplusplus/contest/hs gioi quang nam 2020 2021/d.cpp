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

int k;
string str;
int a[N], dp[N];

void solve(){
    // Something goes here...
    cin>>k>>str;
    int n = str.size();
    for(int i = 0; i<n; i++){
        char c = str[i];
        a[i+1] = c - '0';
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        int count_1 = 0;
        for(int j = i; j<=n; j++){
            if(a[j] == 1){
                count_1++;
            }
            if(count_1 == k){
                ans++;
                //cout<<"Found: "<<i<<" -> "<<j<<endl;
            }else if(count_1 > k) break;
            //cout<<i<<" -> "<<j<<endl;
        }
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