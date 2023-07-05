#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int n , k;
int cnt[N] , a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int count = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        for (int j = 1; j < i; j++)
        {
            if(a[i] + a[j] == k) count++;
        }
    }
    cout<<count;
}