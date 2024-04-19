/*
    author: Qan
*/
#include <bits/stdc++.h>
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

// This shit just for fun
pii binarySearch(int l, int r, int weight){
    int mid = 0;
    pii ans = {0,0};
    while(l<=r){
        mid = (l+r)/2;
        if(samples[mid].first <= weight){
            r = mid - 1;
            if(samples[mid].second > ans.second){
                ans = samples[mid];
            }
        }else{
            l = mid+1;
        }
    }
    return ans;
}

void solve(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>samples[i].first>>samples[i].second;
    }
    int res = 0;
    sort(samples+1, samples+1+n, cmp);
    for(int i = 1; i<=m; i++){
        cin>>c[i];
        int tmp = 0;
        int cur = 0;
        for(int j = 1; j<=n && samples[j].first <= c[i]; j++){
            if(tmp < samples[j].second && stored[j] == false){
                cur = j;
                tmp = samples[j].second;
            }
        }
        stored[cur] = true;
        res += tmp;
    }
    cout<<res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SAMPLE.INP", "r", stdin);
    freopen("SAMPLE.ANS", "w", stdout);
    solve();
}
