/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
vector<int> nums;
int solve(){
    int sz = nums.size();
    int dp[sz+2];
    int dp_cnt[sz+2];
    memset(dp, 1, sz+1);
    memset(dp_cnt, 1, sz+1);
    int maxi = 0, cnt = 0;
    for(int i = 0; i<sz; i++){
        for(int j = 0; j<i; j++){
            if(nums[i] >  nums[j]) {
                if(dp[i] == dp[j] + 1){
                    dp_cnt[i] += dp_cnt[j];
                }else if(dp[i] < dp[j] + 1){
                    dp_cnt[i] = dp_cnt[j];
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(dp[i] == maxi) cnt += dp_cnt[i];
        else if(dp[i] > maxi){
            maxi = dp[i];
            cnt = dp_cnt[i];
        }
    }
    return cnt;
}

signed main(){
    fast;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    cout<<solve();
}
