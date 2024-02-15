#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 5;

int n, k;
int a[N], f[N], pre[N];

int binarySearch(int i){
    int l = 1, r = i, res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        // mid trong khoang tu 1 den i nen chac chan duong
        if(pre[i] - pre[mid-1] <= k){
            r = mid-1;
            res = mid;
        }else l = mid + 1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pre[0] = 0;
    int ans = 0;
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        int tmp = binarySearch(i);
        if(tmp != -1){
            ans += i - tmp + 1;
        }
    }
    cout<<ans;
}
