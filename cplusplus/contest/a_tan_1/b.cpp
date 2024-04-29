/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
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

int n, q;
int a[N];
int cnt[N];

int binarySearchLeft(int l, int r, int target){
    int ans = -1;
    while(l<=r){
        int m = (l+r)/2;
        if(a[m] >= target){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}

int binarySearchRight(int l, int r, int target){
    int ans = -1;
    while(l<=r){
        int m = (l+r)/2;
        if(a[m] <= target){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return ans;
}

void solve(){
    fill(cnt+1, cnt + N + 1, 0);
    // Something goes here...
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int num;
    cin>>q;
    for(int i = 1; i<=q; i++){
        cin>>num;
        if(cnt[num] == 0){
            cout<<"-1 -1"<<endl;
        }else if(cnt[num] == 1){
            int f = binarySearchLeft(1,n,num);
            cout<<f<<" "<<f<<endl;
        }else{
            int first = binarySearchLeft(1,n,num);
            int second = binarySearchRight(first, n, num);
            cout<<first<<" "<<second<<endl;
        }
    }
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