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

int n, k;
string s;
int cnt[N];

void solve(){
    // Something goes here...
    cin>>n>>k>>s;
    int count = 0;
    for(int i = 1; i<= s.size(); i++){
        if(s[i-1] == 'W') count++;
        cnt[i] = count;
    }
    int ans = 1e9;
    for(int i = 1; i <= s.size() - k + 1; i++){
		ans = min(ans, cnt[i + k - 1] - cnt[i - 1]);
	}
	cout << ans;
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