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
const int N = 1000 + 9;

bool multiTestCases = false;

int n;
int a[N][N];

void solve(){
    // Something goes here...
    bool flag[4];
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
            if(a[i][j] < 0) flag[1] = true;
        }
    }
    if(flag[1]){
        cout<<"NO"<<endl;
        return;
    }
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