#include <bits/stdc++.h>
#include <vector>
#define int long long
#define endl "\n";
using namespace std;
const int N = 1e6 + 3;
const int K = 25000;
const int MAX_S = 3005;

int n, S, numk;
struct inp{
    int v, w, k;
} a[N];

struct INFO{
    int v, w;
} info[K+5];

int dp[MAX_S], num[MAX_S];

bool compare(inp a, inp b) {
    return a.v > b.v;
}

void solve(){
    cin >> S >> n;
    for (int i = 1; i <= n; i++){
        cin>>a[i].v>>a[i].w>>a[i].k;
    }
    sort(a+1, a+n+1, compare);

    for(int i = 1; i<=n; i++){
        int tmp = S/a[i].w - num[a[i].w];
        while(tmp && a[i].k){
            tmp--;
            info[++numk] = {a[i].v, a[i].w};
            a[i].k--;
            num[a[i].w]++;
        }
    }
    for(int i = 1; i <= numk; i++){
        for(int j = S; j>=info[i].w; j--){
            dp[j] = max(dp[j], dp[j-info[i].w] + info[i].v);
        }
    }

    int ans = -1;
    for(int i = 1; i<=S; i++) ans = max(ans, dp[i]);
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
