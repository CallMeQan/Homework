/*
    author: Qan
*/
#include <bits/stdc++.h>
#define N 1000006
#define pb push_back
#define int long long
#define endl "\n"
using namespace std;
using ld = long double;

bool loopInput = false;
int a[22];
void fibonacciModified(int t1, int t2, int n) {
    a[1] = t1;
    a[2] = t2;
    for(int i = 3; i<=n; i++){
        a[i] = a[i-1]*a[i-1] + a[i-2];
    }
}

void solve(){
    // Something goes here...
    int num1, num2, num3;
    cin>>num1>>num2>>num3;
    fibonacciModified(num1, num2, num3);
    cout<<a[num3];
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
