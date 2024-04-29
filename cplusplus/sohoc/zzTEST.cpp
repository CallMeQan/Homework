
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n < 4) cout << -1;
	else if (n == 4) cout << 2310;
	else {
		int tmp = 1;
		for (int i = 1; i < n; i++) tmp = (tmp * 10) % 2310;
		cout<<tmp;
	}
}