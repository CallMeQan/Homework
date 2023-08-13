/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n,m;
int a[N];
int non_possible;

void solve(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        non_possible += a[i]%m;
    }
    if(n > non_possible){
        cout<<"YES";
    }
    for(int i = 1; i<=n; i++){
        if(a[i]%m == 0){
            cout<<"YES";
            return;
        }
    }
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