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

const int N = 4e5 + 5;
int n , k;
int a[N] , cnt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    int answer = 0;
    // al + ar = k
    // l = r
    //int x = 2e5; // cái này để né số âm do đk là -1e5 <= k <= 1e5
    int x = 0;
    for(int right = 1 ; right <= n ; right++)
    {
        // a[left] = k - a[right]
        int ad = a[right] + x;
        int ab = k - a[right] + x;
        answer += cnt[ad];
        cnt[ab]++;
    }
    cout<<answer;
}