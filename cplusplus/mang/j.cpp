#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int count;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>> a[i];
    }
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i] * a[i+1] >= 0){
            if((double)(a[i] + a[i+1]) / 2 > sqrt(a[i] * a[i+1])) count++;
        }
    }    
    cout<<count;
}