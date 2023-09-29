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

void solve(){
    // Something goes here...
    cin>>n;
    int nine = (n/6);
    n = n - nine*6;
    int eight = (n/8);
    n = n - eight*8;
    int seven = (n/3);
    n = n - seven*3;
    int six = (n/5);
    n = n - six*5;
    int four = (n/4);
    n = n - four*4;
    int one = (n/2);
    n = n - one*2;
    cout<<nine*9 + eight*8 + seven*7 + six*6 + four*4 + one*1;
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