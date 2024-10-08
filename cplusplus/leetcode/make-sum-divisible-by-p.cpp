/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, p;
vector<int> nums;
int solve(){
    int sz = nums.size();
    vector<int> pre(sz);
    // Build prefix sum
    partial_sum(nums.begin(), nums.end(), pre.begin());
    int rem = pre[sz-1] % p;
    if(rem == 0) return 0;

    unordered_map<int, int> preMod;
    preMod[0] = -1;
    long long preSum;
    int minLen = nums.size();

    for(int i = 0; i< sz; i++){

    }
}

signed main(){
    fast;
    cin>>n>>p;
    int num;
    for(int i = 1; i<=n; i++){
        cin>>num;
        nums.push_back(num);
    }
    cout<<solve();
}
