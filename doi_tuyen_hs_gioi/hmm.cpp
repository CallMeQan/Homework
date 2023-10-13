/*
	author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1005
#define max_size_matrix 105
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
 
typedef pair<int,int> ii;
int MOD = 1e9 + 7;
 
int power(int x, int y){
    int res = 1, cur = x;
    while (y > 0){
        if (y & 1) res = res * cur % MOD;
        cur = cur * cur % MOD;
        y >>= 1;
    }
    return res;
}
 
struct matrix{
    int __size = 0;
    int a[max_size_matrix][max_size_matrix];
 
    void set_size(int size, int val){
        __size = size;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++) a[i][j] = val;
        }
    }
 
    matrix operator * (matrix b){
        matrix c;
        c.set_size(__size, 0);
        for(int i = 0; i < __size; i++)
            for(int j = 0; j < __size; j++)
                for(int k = 0; k < __size; k++){
                    c.a[i][j] += a[i][k] * b.a[k][j];
                    c.a[i][j] %= (MOD - 1);
                }
        return c;
    }
    
    matrix pow(int y){
        matrix ans, res = *this;
        ans.set_size(__size, 0);
        for(int i = 0; i < __size; i++) ans.a[i][i] = 1;
        while (y > 0){
            if (y & 1) ans = ans * res;
            res = res * res;
            y >>= 1;
        }
        return ans;
    }
};
 
const bool moreThanOneTest = false;
int n, k, a[55];
 
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    if (n <= k){
        cout << a[n];
        return;
    }
    if (n == k + 1){
        int res = 1;
        for(int i = 1; i <= k; i++) res = res * a[i] % MOD;
        cout << res;
        return;
    }
    matrix base;
    base.set_size(k + 1, 0);
    base.a[0][0] = 2;
    base.a[k][0] = MOD-2;
    for(int j = 1; j <= k; j++)
        for(int i = 0; i <= k; i++)
            if (i == j - 1) base.a[i][j] = 1;
            else base.a[i][j] = 0;
    base = base.pow(n - k - 1);
    int ans = 1;
    for(int i = 0; i < k; i++){
        int res = 0;
        for(int j = 0; j <= k; j++)
            if (j == 0) res = (res + base.a[j][0]) % (MOD - 1);
            else if (j == i + 1) res = (res + base.a[j][0]) % (MOD - 1);
        ans = ans * power(a[k-i], res) % MOD;
    }
    cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	if (moreThanOneTest){
		int t; cin >> t;
		while (t--) solve();
	} else solve();
}