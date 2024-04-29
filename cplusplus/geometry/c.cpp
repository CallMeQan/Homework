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

int n;
int a[N];

double length_of_vect(pii a, pii b){
    return sqrt(pow(b.fi - a.fi, 2) + pow(b.se - a.se, 2));
}

bool check_square(pii a, pii b, pii c){
    if((a.fi * b.fi + a.se * b.se) == 0) return true;
    
    return false;
}

bool check_can(pii a, pii b, pii c){
    if(length_of_vect(a, b) == length_of_vect(b, c)) return true;
    if(length_of_vect(a,b) == length_of_vect(a,c)) return true;
    if(length_of_vect(b, a) == length_of_vect(b, c) ) return true;
    if(length_of_vect(b, a) == length_of_vect(c, a) ) return true;
    return false;
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        pii a,b,c;
        cin>>a.fi>>a.se>>b.fi>>b.se>>c.fi>>c.se;
        bool can = check_can(a,b,c);

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