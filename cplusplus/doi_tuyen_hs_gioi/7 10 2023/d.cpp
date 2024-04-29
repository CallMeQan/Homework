/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = false;

string str;
int index = 0;
int a[N];

bool isPrime(long long n){
    if(n < 2) return false;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) return false;
    }
    return true;    
}

void solve(){
    int sum = 0;
    int flagged = 0;
    int startCheck = 0;
    // Something goes here...
    cin>>str;
    for(char c : str){
        if(c == ',') {
            startCheck = 1;
            continue;
        }
        int num = c -'0';
        if(!isPrime(num) && startCheck > 0){
            flagged = 1;
        }
        sum += num;

    }
    if(flagged == 0 && isPrime(sum)){
        cout<<"CO";
    }else{
        cout<<"KHONG";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}