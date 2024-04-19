#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+9;
const int MOD = 1e9+7;

int n;
int a[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a[1] = 1;
    a[2] = 1;
    for(int i = 3; i<=n; i++){
        a[i] = (a[i-1] + a[i-2]) % MOD;
    }
    cout<<a[n]<<endl;
}
