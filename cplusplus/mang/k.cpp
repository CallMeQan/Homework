#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>> a[i];
    }
    std::sort(a, a + n);
    for(int i = 0 ; i < n ; i++)
    {
        cout<<a[i]<<" ";
    }
}