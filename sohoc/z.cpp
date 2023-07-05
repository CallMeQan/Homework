//n * (n + 1) * (2 * n + 1)  / 6
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long t;
    cin>>t;
    for(long long i = 1; i<=t; i++){
        long long x;
        cin>>x;
        cout<<x*(x+1)*(2*x+1)/6<<"\n";
    }
}