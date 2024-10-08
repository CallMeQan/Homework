/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N = 705;
const int MAX_N = 1e4 + 5;
bool loopInput = false;

int n, m;
int a[N][N];
bool visited[N][N];
int moveX[] = {0, 0, 1,-1, 1,-1, 1,-1};
int moveY[] = {1,-1, 0, 0,-1, 1, 1,-1};

int ans = 0;

// Loang
void bfs(int num1, int num2)
{
    bool peak = true;
    queue<pii> q;
    q.push({num1, num2});
    visited[num1][num2] = true;
    while (!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int i = 0; i < 8; i++){
            int u = x + moveX[i];
            int v = y + moveY[i];

            if (u > n || u < 1) continue;
            if (v > m || v < 1) continue;

            if(a[x][y] < a[u][v])
                peak = false;
            else
                if(a[x][y] == a[u][v] && !visited[u][v]){
                    visited[u][v] = true;
                    q.push({u, v});
            }
        }
    }

    if(peak) ans++;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int x = 1; x<=n; x++){
        for (int y = 1; y<=m; y++)
            {
            if(a[x][y] > 0 && !visited[x][y])
                bfs(x, y);
            }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t;
        cin >> t;
        while (t--){solve();}
    }
    else{solve();}
}
