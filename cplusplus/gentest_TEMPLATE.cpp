#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; i++)

using namespace std;

const int NTEST = 1000;
const string NAME = "TVT";

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    assert(l <= r);
    return l + rd() % (r - l + 1);
}

void gentest(){
    ofstream inp((NAME + ".INP").c_str());
    int n = Rand(1, 10);
    inp << n << '\n';
    rep(i, 1, n) inp << Rand(1, 1e4) << ' ';
    inp.close();
}

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
