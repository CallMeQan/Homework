/*
    author: Qan
*/
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N], dp[N];

void solve()
{
    // Something goes here...
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {

                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}