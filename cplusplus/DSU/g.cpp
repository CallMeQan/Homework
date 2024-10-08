#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define rep(i, l, r) for (int i = l; i <= r; i++)
using namespace std;
const int N = 3000005;
typedef pair<int, int> ii;
typedef vector<int> vi;
const bool moreThanOneTest = 0;
const int MOD = 1e9 + 7;
const int INF = 1e18;

int n, m, p, q, l;
int par[N], sz[N];
char a[1505][1505];
int movei[4] = {-1, 0, 1, 0};
int movej[4] = {0, -1, 0, 1};

int fs(int v)
{
    return v == par[v] ? v : par[v] = fs(par[v]);
}

void us(int a, int b)
{
    a = fs(a);
    b = fs(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

bool inside(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}

int conv(int x, int y)
{
    return (x - 1) * m + y;
}

int conv(ii x)
{
    return (x.fi - 1) * m + x.se;
}

void solve()
{
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    rep(i, 1, n) rep(j, 1, m) par[conv(i, j)] = conv(i, j), sz[conv(i, j)] = 1;
    vector<ii> swan;
    rep(i, 1, n) rep(j, 1, m)
    {
        if (a[i][j] == 'L')
            swan.pb({i, j});
    }
    rep(i, 1, n) rep(j, 1, m)
    {
        if (a[i][j] == 'X')
            continue;
        rep(k, 0, 3)
        {
            int i2 = i + movei[k], j2 = j + movej[k];
            if (!inside(i2, j2))
                continue;
            if (a[i2][j2] != 'X')
            {
                us(conv(i, j), conv(i2, j2));
            }
        }
    }
    if (fs(conv(swan[0])) == fs(conv(swan[1])))
    {
        cout << 0 << '\n';
        return;
    }
    rep(day, 1, INF)
    {
        vector<pair<ii, ii>> v;
        rep(i, 1, n) rep(j, 1, m)
        {
            if (a[i][j] == 'X')
                continue;
            rep(k, 0, 3)
            {
                int i2 = i + movei[k], j2 = j + movej[k];
                if (!inside(i2, j2))
                    continue;
                v.pb({{i, j}, {i2, j2}});
            }
        }
        for (auto x : v)
        {
            a[x.se.fi][x.se.se] = '.';
            us(conv(x.fi), conv(x.se));
        }
        rep(i, 1, n) rep(j, 1, m)
        {
            if (a[i][j] == 'X')
                continue;
            rep(k, 0, 3)
            {
                int i2 = i + movei[k], j2 = j + movej[k];
                if (!inside(i2, j2))
                    continue;
                if (a[i2][j2] != 'X')
                {
                    us(conv(i, j), conv(i2, j2));
                }
            }
        }
        if (fs(conv(swan[0])) == fs(conv(swan[1])))
        {
            cout << day << '\n';
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (moreThanOneTest)
    {
        int t;
        cin >> t;
        while (t--)
            solve();
    }
    else
        solve();
}
