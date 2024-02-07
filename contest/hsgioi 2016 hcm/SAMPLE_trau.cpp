
/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define N 300005
#define pii pair<int,int>
#define int long long
#define endl "\n"
using namespace std;

int n,m;
int c[N];

bool stored[N];
pii samples[N];

bool cmp(pii &a, pii &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve(){
    samples[0] = {0, -1};
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>samples[i].first>>samples[i].second;
    }
    int res = 0;
    sort(samples+1, samples+1+n, cmp);
    for(int i = 1; i<=m; i++){
        cin>>c[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SAMPLE.INP", "r", stdin);
    freopen("SAMPLE.OUT", "w", stdout);
    solve();
}
