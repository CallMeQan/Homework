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
    long long maxNumber = -1e9 - 1;
    for(int i = 1 ; i <= n ; i++)
    {
        long long num = 0;
        cin >> num;
        a[i] = num;
        if(num < minNumber)
            minNumber = num;
        else if(num > maxNumber)
            maxNumber = num;
    }
    int countMax = 0;
    int countMin = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] == minNumber)
            countMin++;
        else if(a[i] == maxNumber)
            countMax++;
    }
    cout<<minNumber<<" "<<countMin<<"\n";
    cout<<maxNumber<<" "<<countMax<<"\n";
}