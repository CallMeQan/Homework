#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int n;
long long a[1000003];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long total = 0;
    int count = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        long long num;
        cin>>num;
        if((i % 2 == 0) && (num % 2 != 0)){
            total = total + num;
            count++;
        }
    }
    if(count < 1){
        cout<<"NO";
    }else{
        cout << setprecision(5) << fixed << (double long)(total)/count;
    }
}