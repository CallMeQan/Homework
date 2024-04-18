/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 2024;
const int N = 1e6 + 9;

bool loopInput = false;

int n;
int a[N], b[N];
bool checker[3];
void solve(){
    // Something goes here...
    cin>>n;
    int tmp = log(n) / log(2024);
    cout<<tmp;
    a[1] = 1012;
    a[2] = 2024;
    for(int i = 3; i<=n; i++){
        if(n > N){
            
        }
    }
    cout<<a[n];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}