// al + ar = k
//
// al = k - ar
//
// Cho số chỉ của a[left] là left, và tương tự a[right]
//
// Cơ bản là cnt[i]: là số thằng left sao cho a[left] = i
// Nhưng theo bài đếm cặp thì cnt[k - a[r]]: là số thằng left sao cho a[left] = k - a[right]

// điều kiện là left < right

// right: 
//     cnt[]: left: 1 -> right - 1
    
// left = right -> cnt[a[right]]++;
// right + 1
//     cnt[]: left: 1 -> right

// right: 1 -> n
//     answer += cnt[k - a[right]];
//     cnt[a[right]]++;

#include<bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 1;
long long n , k;
long long a[N] , cnt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(long long i = 1 ; i <= n ; i++) cin >> a[i];
    long long answer = 0;
    for(long long right = 1 ; right <= n ; right++)
    {
        // a[left] = k - a[right]
        answer += cnt[a[right] % k];
        cnt[a[right] % k]++;
    }
    cout << answer;
}

// -1e5 <= a[i] <= 1e5

// -2e5 <= k + ai <= 2e5