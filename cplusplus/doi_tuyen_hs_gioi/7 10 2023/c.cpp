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
const int N = 1e3 + 9;

bool multiTestCases = false;

int m, n;
int a[N], b[N];

vector<pii> arr;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first >= b.first;
}

void solve(){
    // Something goes here...
    cin>>m>>n;
    for(int i = 1; i<=m; i++){
        cin>>a[i];
        arr.push_back({a[i], 1});
    }
    
    for(int i = 1; i<=n; i++){
        cin>>b[i];
        arr.push_back({b[i], 2});
    }

    sort(arr.begin(), arr.end(), compare);
    int ans = 0;
    int count1 = 0;
    int count2 = 0;

    for(const auto& p : arr){
        if((count1 == 3 && count2 == 1) || (count1 == 1 && count2 == 3) || (count1 == 2 && count2 == 2)){
            break;
        }
        if(p.se == 1){
            if(count1>=3) continue;
            ans += p.fi;
            count1++;
        }
        if(p.se == 2){
            if(count2 >=3) continue;
            ans += p.fi;
            count2++;
        }
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