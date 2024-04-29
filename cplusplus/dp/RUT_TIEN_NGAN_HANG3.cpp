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

int n, closeTime;
int dp[N][105];
struct person{
    int a, time, cost;

    bool operator < (const person &b) const{
        if(b.time != time) return time < b.time;
        return a > b.a;
    }
} people[N];

void solve(){
    // Something goes here...
    cin>>n>>closeTime;
    closeTime++;
    for(int i = 1; i<=n; i++){
        cin>>people[i].a>>people[i].time>>people[i].cost;
        people[i].time++;
    }
    sort(people+1, people+n+1);
    for(int i = 1; i<=n; i++)
    {
        for(int cur_Time = 0; cur_Time <= closeTime; cur_Time++){
            dp[i][cur_Time] = dp[i-1][cur_Time];
            if(cur_Time <= people[i].time && cur_Time >= people[i].cost){
                dp[i][cur_Time] = max(dp[i][cur_Time], dp[i-1][cur_Time - people[i].cost] + people[i].a);
            }
        }
    }
    int ans = dp[n][0];
    for(int i = 1; i<=closeTime; i++) ans = max(ans, dp[n][i]);
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