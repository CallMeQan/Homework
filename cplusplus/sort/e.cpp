#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e6+5;

int n, m;
pii a[N];

bool cmp(pii a, pii b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        int num;
        cin>>num;
        a[i].first = num;
        int tmp = 0;
        while(num > 0){
            tmp += num % 10;
            num /= 10;
        }
        a[i].second = tmp;
    }
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i<=n; i++) {
        cout<<a[i].first<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

