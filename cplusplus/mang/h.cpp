#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long minNumber = 1e9 + 1;
    for(int i = 1 ; i <= n ; i++)
    {
        long long num = 0;
        cin >> num;
        a[i] = num;
        if(num < minNumber)
            minNumber = num;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] == minNumber)
            cout << i << " ";
    }
}