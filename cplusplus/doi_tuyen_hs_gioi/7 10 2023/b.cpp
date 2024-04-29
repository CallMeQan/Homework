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

int m;
int a[N];

void solve(){
    // Something goes here...
    cin>>m;
    if(m<3) {
        cout<<0;
        return;
    }
    int multiplesOf3 = m / 3;
    int multiplesOf15 = m / 15;
    int sum1 = multiplesOf3 * (multiplesOf3 + 1) / 2 * 3;
    int sum2 = multiplesOf15 * (multiplesOf15 + 1) / 2 * 15;
    cout<<sum1-sum2;

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