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

int u1, d, un;
int a[N];

bool check(double a){
    return (a - (int)a) == 0.0;
}

void solve(){
    // Something goes here...
    cin>>u1>>d>>un;
    double n = (double)((double)(un - u1) / (double)d) + (double)1.0;
    if(check(n)){
        cout<<(int)n<<endl;
    }else cout<<-1;
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