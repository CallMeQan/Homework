/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 50
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

bool loopInput = false;

int mod = 1000000007;

int n, k;
int a[N];

struct Matrix {
    vector <vector <int> > data;

    int row() const { return data.size(); } 

    int col() const { return data[0].size(); }

    auto & operator [] (int i) { return data[i]; }
    
    const auto & operator[] (int i) const { return data[i]; }

    Matrix() = default;
    
    Matrix(int r, int c): data(r, vector <int> (c)) { }

    Matrix(const vector <vector <int> > &d): data(d) { }

    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x : d.data) {
            for (auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }

    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        Matrix a = *this;
        assert(a.col() == b.row()); 
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < a.col(); ++k){
                    c[i][j] += 1ll * a[i][k] % mod * (b[k][j] % mod) % mod;
                    c[i][j] %= mod;
                }
        return c;
    }

    Matrix pow(long long exp) {
        assert(row() == col());  
        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};

//https://codeforces.com/group/ppMtstS1O2/contest/411441/problem/H
void solve(){
    Matrix A = Matrix({
        {1,1},
        {1,0}
    });
    int t;
    cin>>t;
    while(t--){}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        cin >> n;
        for(int i = 1; i<=100;i++)solve();
    } else solve();
}