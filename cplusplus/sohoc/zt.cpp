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

int L, R;

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return root * root == n;
}

void solve(){
    // Something goes here...
    cin>>L>>R;
    int count = 0;
    for(int a = L; a <= R; a++){
        for(int b = a; b <= R; b++){
            int ucln = __gcd(a, b);
            if(ucln > 1 && isPerfectSquare(ucln)) count++;
        }
    }
    cout<<count;
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