#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6+5;

int n, m;
int a[N];

bool cmp(int a, int b){return a > b;}

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i<=n; i++) cout<<a[i]<<" ";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

