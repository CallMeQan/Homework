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
const int N = 1e3 + 5;

bool multiTestCases = false;

int n,K;
int a[N], b[N], f[N][1024 * 4 + 5];

void solve(){
    // Something goes here...
    cin >> n >> K;
    K *= 1024;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i] >> b[i];

    // set dữ liệu ban đầu
    f[0][0] = 0;
    for(int i = 1 ; i <= K ; i++)
    	f[0][i] = -1e18;
 
    for(int i = 1 ; i <= n ; i++)
    {
    	for(int j = 0 ; j <= K ; j++)
    	{
    		// tính f[i][j]
    		f[i][j] = f[i - 1][j]; // ko lấy bức ảnh loại i
    		if(j - a[i] >= 0) // lấy >= 1 bức ảnh loại i
    			f[i][j] = max(f[i][j] ,  f[i][j - a[i]] + b[i]);
    	}
    }
 
    int res = -1e18;
    for(int j = 0 ; j <= K ; j++)
        res = max(res , f[n][j]);
    cout << res;

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