// Điều kiện: a[i] < a[i+1] < ...

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int n , q;
int cnt[N] , a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int maxNum = -1e6-3;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i]; 
        cnt[a[i]]++;
        maxNum = max(maxNum, a[i]);
    }
    for (int i = 1; i <= maxNum; i++)
    {
        if(cnt[i] > 1)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}