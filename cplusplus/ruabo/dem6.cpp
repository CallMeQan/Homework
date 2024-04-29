#include<bits/stdc++.h>
using namespace std;

const long long N = 4e6 + 1;
long long n , k;
long long a[N] , cnt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(long long i = 1 ; i <= n ; i++) cin >> a[i];
    long long answer = 0;
    long long x = 2e9;
    for(long long right = 1 ; right <= n ; right++)
    {
        // a[left] = k - a[right]
        answer += cnt[(a[right]+ x) % k];
        cnt[(a[right] + x) % k]++;
    }
    cout << answer;
}

// -1e5 <= a[i] <= 1e5

// -2e5 <= k + ai <= 2e5