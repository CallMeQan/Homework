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
const int N = 1e6 + 9;

bool multiTestCases = false;

int n, k;
int a[N], dp[N];

void solve(){
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        dp[i] = 1e18;
        // Do ta đang tìm chi phí thấp nhất
    }
    // Bước 1: khởi tạo giá trị ban đầu
    dp[1] = 0;
    // Bước 2: tìm công thức dp
    /*
        Từ vị trí thứ nhất hay bất kì, ếch có thể nhảy trong khoảng k
        vì thế ta lật ngược bài toán lại
        từ vị trí i, trong khoảng k trước nó, từ vị trí j trong khoảng k đi đến i tốn bao nhiêu, lấy ít nhất.
        => min(dp[j] + |a[i] - a[j]|)

    Bước 3: Viết mã giả
        i: 2 -> n
            j: i-1 -> i-k (1 nếu i-k âm) (dùng max())
                dp[j] = min(dp[i], dp[j] + |a[i] - a[j]|)

    =>  đáp án là dp[n]
    */
    for(int i = 2; i<=n; i++){
        for(int j = i-1; j >= max((int) 1, i-k); j--){
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
    cout<<dp[n];
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