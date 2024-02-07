#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e6+5;

int n, m;
pair<int, pii> a[N];

bool cmp(pair<int, pii> a, pair<int, pii> b){
    int sum1 = a.first + a.second.first + a.second.second;
    int sum2 = b.first + b.second.first + b.second.second;
    if(sum1 == sum2){
        if(a.first == b.first){
            return a.second.first > b.second.first;
        }
        return a.first < b.first;
    }
    return sum1< sum2;
}

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i].first>>a[i].second.first>>a[i].second.second;
    }
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i<=n; i++) {
        cout<<a[i].first<<" "<<a[i].second.first<<" "<<a[i].second.second<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

