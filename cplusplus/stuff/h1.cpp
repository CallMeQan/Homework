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

/* Input: 7 3 1 2 3
a[1] = 1
a[2] = 2
a[3] = 3
a[4] = a[3] * a[2] * a[1] = 3 * 2 * 1 = 6
a[5] = a[4] * a[3] * a[2] = 6 * 3 * 2 = 36
a[6] = a[5] * a[4] * a[3] = 36 * 6 * 3 = 648
a[7] = a[6] * a[5] * a[4] = 648 * 36 * 6 = 139,968
Matrix (N, K);
*/

//https://codeforces.com/group/ppMtstS1O2/contest/411441/problem/H
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= k; ++i) cin >> a[i];
    Matrix base(k, 1);
    for (int i = 1; i <= k; ++i) base[i - 1][0] = a[i];
    Matrix D(k,k);
    for (int i = 0; i < k-1; ++i) D[i][i+1] = 1;
    for (int i = 0; i < k; ++i) D[k-1][i] = 1;
    
}
/*
Tài liệu nói rằng từ thời xa xưa, cụ tổ Pirate đã xây dựng từng hòn đảo bằng cách chở dừa đến và chất thành đống ở giữa biển, các trái dừa này sẽ mọc ra những cây dừa và thế là một hòn đảo dừa được tạo ra. Lịch sử nói rằng K năm đầu tiên là thời kì khó khăn nhất của vương quốc dừa. Do có một số hòn đảo chất lượng không tốt nên bị mất đi và việc Pirate kiên trì tạo thêm các hòn đảo mới nên số lượng các hòn đảo qua K năm đầu tiên lên xuống thất thường nhưng luôn có ít nhất một đảo. Số lượng hòn đảo trong K năm đầu được lịch sử ghi lại trong dãy số a[1], a[2],... , a[K]. Sau K năm đó, tức là kể từ năm K+1, các cây dừa trên hòn đảo đã trưởng thành và cho trái, các trái dừa rớt xuống biển và tự động tạo nên các hòn đảo dừa mới một cách tự nhiên. Số lượng đảo dừa từ đó tăng một cách chống mặt và vương quốc dừa trở thành một đại cường quốc. Lịch sử cũng nói lại rằng số lượng đảo dừa trong năm thứ i sẽ bằng tích số lượng đảo dừa của K năm trước. Tức là số lượng đảo dừa của vương quốc trong năm i bằng a[i] = a[i-1] * a[i-2] * ... * a[i-K]. Mặc dù vương quốc đã trải qua nhiều thăng trầm, chiến tranh liên miên nhưng số lượng đảo dừa qua từng năm vẫn tăng đều theo công thức đó.
Thế là có đủ thông tin để yenthanh132 có thể tính được số lượng đảo dừa của vương quốc dừa. Nhưng tính tới thời điểm hiện tại đã là năm tồn tại thứ N của vương quốc và N là một số rất lớn nên không ai có thể tính được. Do đó yenthanh132 nhờ bạn tính giúp anh ta số lượng đảo dừa của vương quốc dừa theo modulo 1000000007 ( = 10^9 + 7).
- Cho số N, K và dãy số a[1], a[2],... , a[K] - số đảo dừa trong vương quốc qua K năm đầu
- Với i>K ta có a[i] = a[i-1] * a[i-2] * a[i-3] * ... * a[i-K];
- Tính a[N], do số lượng hòn đảo rất lớn nên yenthanh132 chỉ yêu cầu bạn tính phần dư của kết quả khi chia cho số 1000000007 ( = 10^9 + 7). Tức là tính a[N]
Lưu ý: Những đường dẫn đến bài tập bên ngoài chỉ mang tính chất tham khảo cho vui, không liên quan đến bài này.
Input
Dòng đầu tiên gồm hai số nguyên dương N, K (1 ≤ N ≤ 1e9, 1 ≤ K ≤ 50, K < N).
Dòng thứ hai ghi K số nguyên dương, số thứ i của dãy số là ai (1 ≤ ai ≤ 1e9)
Output
Ghi ra kết quả theo modulo 1000000007 (10^9 + 7).
*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}