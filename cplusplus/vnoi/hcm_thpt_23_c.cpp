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
const int N = 5e5 + 9;

bool multiTestCases = false;

int n;
int dp[N];

struct Rectangle{
    int x, y, D, C, val;
    bool operator < (const Rectangle& other) const {
        return x < other.x;
    }

};

vector<Rectangle> rects;

bool tiepXuc(Rectangle rect1, Rectangle rect2){
    bool isXTouching = (rect1.x <= rect2.x + rect2.D) && (rect1.x + rect1.D >= rect2.x);

    bool isYTouching = (rect1.y <= rect2.y + rect2.C) && (rect1.y + rect1.C >= rect2.y);

    return isXTouching || isYTouching;
}


void solve(){
    // Something goes here...
    int ans = -1;
    cin>>n;
    for(int i = 1; i<=n; i++){
        int x, y, D, C;
        cin>>x>>y>>D>>C;

        rects.push_back({x,y,D,C});
    }
    sort(rects.begin(), rects.end());

    dp[0] = rects[0].D * rects[0].C;
    for (int i = 1; i < n; i++) {
        dp[i] = rects[i].D * rects[i].C;
        if(tiepXuc(rects[i], rects[i-1])){
            dp[i] += dp[i-1];
        }
        ans = max(ans, dp[i]);
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