#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int n;
int cnt[10] , a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i]; 
        while(a[i])
        {
            int last = a[i] % 10;
            cnt[last]++;
            a[i] /= 10;
        }
    }
    for(int i = 0 ; i <= 9 ; i++)
    {
        cout<<cnt[i]<<" ";
    }
}