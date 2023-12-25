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
const int N = 505;

bool multiTestCases = false;

int n;
int a[N][N], dist[N][N];
bool visted[N][N];
int moveX[] = {0, 0,-1, 1};
int moveY[] = {1,-1, 0, 0};
queue<pair<int,int>> q;

bool bfs(int distMax){
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++) visted[i][j] = false;
    q.push({1, 1});
    visted[1][1] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nextX = x + moveX[i];
            int nextY = y + moveY[i];
            if(nextX>n || nextY>n || nextX<1 || nextY < 1 || visted[nextX][nextY]) continue;
            if(abs(a[nextX][nextY] - a[x][y]) <= distMax){
                visted[nextX][nextY] = true;
                q.push({nextX, nextY});
            }
        }
    }
    return visted[n][n];
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++) cin>>a[i][j];
    int ans = 1e9;
    int l = 1, r = 1e6;
    while(l<=r){
        int mid = (l+r) >> 1;
        if(bfs(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        }else{l = mid + 1;}
    }
    cout<<ans;
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