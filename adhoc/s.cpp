/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 100005
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n;
int ans = 0;
bool cnt[N];
array<int> ans_arr;
int a[N];

bool binarySearch(int l, int r, int val){
    while(l <= r){
        int mid = (l+r)/2;
        if(a[mid] == val){
            return true;
        }else if(a[mid] < val){
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    return false;
}
//10
//1 3 5 9 21 31 39 61 71 73
void solve(){
    // Something goes here...
    fill(cnt, cnt+N, false);    
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    int d = a[2] - a[1];
    int max_n = ((a[n] - a[1])/d)+1;
    if(d == 0) {
        cout<<"-1";
        return;
    }
    // an = a1 + (n-1)d
    // => ((an - a1)/d) + 1 = n
    for(int i = 1; i<=n; i++){
        int res = ((a[i] - a[1])/d) + 1;
        cnt[res] = true;
    }
    ans++;
    ans_arr.push_back(a[1] - d);
    for(int i = 1; i <= max_n; i++){
        if(!cnt[i]){
            ans++;
            ans_arr.push_back(a[1] + (i-1)*d);
        }
    }
    ans++;
    ans_arr.push_back(a[n] + d);
    cout<<ans<<endl;
    for(int i = 0; i<ans; i++) cout<<ans_arr[i]<<" ";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}