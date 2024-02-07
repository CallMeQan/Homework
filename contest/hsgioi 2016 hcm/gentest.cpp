#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; i++)

using namespace std;

const int NTEST = 1000;
const string NAME = "JACKFT";

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    assert(l <= r);
    return l + rd() % (r - l + 1);
}

/* For JACKFT
void gentest(){
    ofstream inp((NAME + ".INP").c_str());
    int n = Rand(1, 100);
    int l = Rand(1, 1000);
    int k = Rand(1,100);
    inp << n << '\n';
    rep(i, 1, n) inp << Rand(-1e6, 1e6) << ' ';
    inp <<'\n';
    rep(i, 1, n) inp << Rand(1, 1e6)<<' ';
    inp.close();
}
*/

int32_t main(){
    srand(time(NULL));
    rep(i, 1, NTEST){
        gentest();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        if (system(("fc " + NAME + ".OUT " + NAME + ".ANS").c_str()) != 0){
            cout << "TEST " << i << ": WA" << endl;
            return 0;
        }
        cout << "TEST " << i << ": O-OKEEE" << endl;
    }
}
