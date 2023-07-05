// cnt[10 ^ 7]
// 6
// -1 1 2 1 2 3, 1≤ai≤10^7
// cnt[1] = 2
// cnt[2] = 2
// cnt[3] = 1
// cnt[-1] = 1

// cnt[i]: là số thằng trong dãy có giá trị bằng i 

// truy vấn: giá trị i xuất hiện bao nhiêu lần trnog dãy 

// thằng 2 xuất hiện nhiêu lần trong dãy : cnt[2]

// thằng x xuất hiện nhiêu lần trong dãy : cnt[x]


#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int n , q;
int cnt[N] , a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i]; 
        cnt[a[i]]++; 
    }
    cin >> q;
    for(int i = 1 ; i <= q ; i++)
    {
        int x;
        cin >> x;
        cout << cnt[x] << "\n";
    }
}