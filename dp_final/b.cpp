#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+9;
const int MOD = 1e9+7;

int n;
int a[N];
int pre[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre[0] = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }
    int q; cin>>q;
    for(int i = 1; i<=q; i++){
        int l, r;
        cin>>l>>r;
        cout<<pre[r] - pre[l-1]<<endl;
    }
}
