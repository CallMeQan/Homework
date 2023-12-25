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

int n, x;
int a[N];
vector<pii> b;

void solve(){
    // Something goes here...
    cin>>n>>x;
    for(int i = 1; i<=n; i++) cin>>a[i];
    int j = n;
    for(int i = 1; i<=n;i++){
        while(j >= 1 && a[i] + a[j] > x){
            j--;
        }
        if(i < j && a[i] + a[j] == x){
            cout<<i<<" "<<j<<endl;
            exit(0);
        }
    }
    cout<<"No solution";
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