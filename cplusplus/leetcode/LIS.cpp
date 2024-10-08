/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int nums[2505];
int solve(){
    int dp[n+5];
    int res = 0;
    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(nums[i] >  nums[j]) {
                    cout<<nums[i]<<" is bigger "<<nums[j]<<endl;
                dp[i] = max(dp[i], dp[j] + 1);
            }else{
                cout<<"Skipping "<<nums[j]<<endl;
            }
        }
        cout<<"Current dp["<<i<<"] = "<<dp[i]<<endl;
        res = max(res, dp[i]);
    }
    return res;
}

signed main(){
    fast;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    cout<<solve();
}
