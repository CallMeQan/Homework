#include<bits/stdc++.h>
#include <vector>
using namespace std;
int n;
int a[1000003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long maxNum = -1e9 - 1;
    for(int i = 1 ; i <= n ; i++)
    {
        long long num = 0;
        cin >> num;
        a[i] = num;
        if(num > maxNum){
            maxNum = num;
        }
    }
    vector<long long> b;
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] != maxNum) b.push_back(a[i]);
    }
    for (long long i: b)
    {
        cout<<i<<" ";
    }
    
}