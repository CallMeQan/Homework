#include<bits/stdc++.h>
using namespace std;

const long long N = 4e5 + 5;
long long n;
long long a[N] , cnt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(long long i = 1 ; i <= n ; i++) cin >> a[i];
    long long answer = 0;
    long long x = 2e5; // cái này để né số âm do đk là -1e5 <= k <= 1e5
    for(int right = 1 ; right <= n ; right++)
    {
        answer += cnt[a[right] - right + x];
        cnt[a[right] - right + x]++;
    }
    cout <<answer;
}