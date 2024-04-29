#include <bits/stdc++.h>
#include <string>

using namespace std;
string x,y;
long long x_converted, y_converted;
bool isPerfectSquare(long long n) {
    long long root = sqrt(n);
    return root * root == n;
}

long long binaryToDecimal(string n) {
    long long number = 0;
    int ab = n.length();
    for (int i = 0; i < ab; i++) {
        number <<= 1;
        if (n[i] == '1') {
            number |= 1;
        }
    }
    return number;
}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long count = 0;
    cin>>x>>y;
    x_converted = binaryToDecimal(x);
    y_converted = binaryToDecimal(y);
    long long root_x = sqrt(x_converted);
    long long root_y = sqrt(y_converted);
    if(isPerfectSquare(x_converted)) cout<<root_y-root_x+1;
    else cout<<root_y-root_x;
}