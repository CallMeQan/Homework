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
const int N = 1e5 + 9;

bool multiTestCases = false;

int n,i,j;
pii b[N];
int par[N], a[N], sz[N];
int dp[N];
bool checked[N];
bool gg(pii x, pii y){
    return x.fi > y.fi;
}
int acs(int f)
{
    if(f == par[f]) return f;
    else return par[f] = acs(par[f]);
}
 
void join(int u, int v)
{
    int g = acs(u);
    int h = acs(v);
 
    if(g!=h)
    {
        par[g] = h;
        sz[h] += sz[g];
    }
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        par[i] = i;
        sz[i] = 1;
        checked[i] = false;
    }

    for(int i = 1; i<=n ; i++){
        cin>>a[i];
        b[i] = {a[i], i};
    }
    sort(b+1, b+n+1, gg);
    dp[0] = 1;
    /*
        i = 4:
            + - +
        1 2 3 4 5 4 3 2 1 6
        
    */
    for(int i = 1; i<=n; i++){
        checked[b[i].se] = true;
        dp[i] = dp[i-1];

        if(b[i].se + 1 <= n && checked[b[i].se + 1] == true)
        {
            join(b[i].se, b[i].se + 1);
            dp[i] = max(sz[acs(b[i].se)], dp[i-1]);
        }
        if (b[i].se - 1 >= 1 && checked[b[i].se - 1] == true)
        {
            join(b[i].se - 1, b[i].se);
            dp[i] = max(sz[acs(b[i].se)], dp[i-1]);
        }
    }
    for(i=1;i<=n;i++)
    {
        int l = 1;
        int r = n;
        int ans = 1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(dp[mid] >= i)
            {
                ans = b[mid].fi;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout<<ans<<" ";
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