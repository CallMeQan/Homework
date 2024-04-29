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
const int N = 2e5 + 9; // n * k <= 2e5

bool multiTestCases = true;

/*
4 4
1 2 3 4 base
2 3 1 4
3 2 1 4
4 2 3 1

[1]{
    [1]{},
    [2]{2, 3},
    [3]{3, 4},
    [4]{4, 5}
}

[2]{
    [1]{3, 4},
    [2]{2, 3},
    [3]{3, 4, 2, 3},
    [4]{4, 5, 4, 5}
}

[3]{
    [1]{3, 4, 3, 4},
    [2]{2, 3, 2, 3},
    [3]{3, 4, 2, 3},
    [4]{4, 5, 4, 5, 4, 5}
}
[4]{
    [1]{3, 4, 3, 4, 4, 5},
    [2]{2, 3, 2, 3, 2, 3},
    [3]{3, 4, 2, 3, 3, 4},
    [4]{4, 5, 4, 5, 4, 5}
}
- - - - -
1 2 3 4 5
skip pos 1 because we counting on 2
=> 4 must be on 4 or 5
=> 3 must be on 3 or 4
=> 2 must be on 2 or 3
=> 1 must be on 3 or 4
=> 2 3 1 4

Actual order: 2 3 1 4
*/
int cnt = 0;
void dfs(int u, vector<bool> &vis, vector<vector<int>> &g, vector<int> &tmp){
    vis[u] = true;
    for(auto val: g[u]){
        if(!vis[val]){
            dfs(val, vis, g, tmp);
        }
    }
    tmp[u] = cnt;
    cnt++;
}

void solve(){
    // Something goes here...
    int n, k;
    cin>>n>>k;
    vector<vector<int>> a(k+9, vector<int>(n+9));
    vector<bool> visited(n+9);
    vector<int> tracked(n+9, -1);
    vector<vector<int>> graph(n+9);
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
        }
        // j = 1 is author
    }
    for(int i = 1; i<=k; i++){
        for(int j = 2; j+1<=n; j++){
            graph[a[i][j]].push_back(a[i][j+1]);
        }
    }
    for(int i = 1; i<=n; i++){
        if(tracked[i] == -1){
            dfs(i, visited, graph, tracked);
        }
    }
    for(int i = 1; i<=k; i++){
        for(int j = 2; j+1<=n; j++){
            if(tracked[a[i][j]] < tracked[a[i][j+1]]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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