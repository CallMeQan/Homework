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

int m;

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
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}