#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e6+5;

int n, m;
pair<int, int> a[N];
// orginal number, first appear index,
pii countAppeared[N];

bool cmp(pair<int, int> a, pair<int, int> b){
    int count1 = countAppeared[a.first].first;
    int count2 = countAppeared[b.first].first;
    if(count1 == count2){
        return a.second < b.second;
    }
    return count1 > count2;
}

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        int num;
        cin>>num;
        a[i].first = num;
        countAppeared[num].first++;
        if(countAppeared[num].first < 2){
            countAppeared[num].second = i;
            a[i].second = i;
        }else{
            a[i].second = countAppeared[num].second;
        }
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

