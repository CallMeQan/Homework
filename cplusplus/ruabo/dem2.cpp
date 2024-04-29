#include<bits/stdc++.h>
using namespace std;

const long long N = 9e5 + 5;
long long n,k;
long long a[N] , cnt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(long long i = 1 ; i <= n ; i++) cin >> a[i];
    long long answer = 0;
    long long x = 3e5; // cái này để né số âm do đk là -1e5 <= k <= 1e5
    for(int y = 1 ; y <= n ; y++)
    {
        for (int z = y + 1; z <= n; z++)
        {
            answer += cnt[k - a[y] - a[z] + x];
        }
        cnt[a[y] + x]++;
    }
    cout <<answer;
}