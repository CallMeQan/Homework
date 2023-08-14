/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = true;

int a;

bool isPrime(int n){
    if(n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) return false;
    }
    return true;    
}

bool isPerfectSquare(int num) {
    int root = sqrt(num);
    return (root * root == num);
}

void solve(){
    // Something goes here...
    cin>>a;
    
    if(a==1){
        cout<<1<<" "<<1<<endl;
    }else if(isPrime(a)){
        cout<<1<<" "<<a<<endl;
    }else if(isPerfectSquare(a)){
        cout<<sqrt(a)<<" "<<1<<endl;
    }else{
        int largest = -1;
        for(int x = 2;x<=sqrt(a); x++){
            int x_tmp = x*x;
            if(a%x_tmp == 0)largest = x;
        }
        if(largest>-1){
            cout<<largest<<" "<<a/(largest*largest)<<endl;
        }else{
            cout<<1<<" "<<a<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}