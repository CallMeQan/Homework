/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define PI 3.1459
#define endl "\n"
using namespace std;

// =================== This solution is broken ======================
bool multiTestCases = false;
int n;

struct Point{
    int x,y;
    int id;
    bool operator < (const Point& other){
        if(x != other.x) return x<other.x;
        return y < other.y;
    }
};

struct cmp{
    bool operator () (const Point& a, const Point& b) const {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }
};

vector<Point> points;
set<Point, cmp> T;

int distance(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        int x, y;
        cin>>x>>y;
        points.push_back({x,y,i});
    }

    int squared_d = distance(points[0], points[1]); // Lưu bình phương của d
    int res_id1 = 0, res_id2 = 1;
    
    sort(points.begin(), points.end()); // Sắp xếp các điểm theo hoành độ
    
    for (auto p : points) {
        int x = p.x, y = p.y;
        int id = p.id;
        
        int d = sqrt(squared_d);
        Point cur = {-1000001, y - d, id};
        
        while (1) { // Tìm tất cả các điểm có tung độ trong khoảng [y - d, y + d]
            auto it = T.upper_bound(cur);
            
            if (it == T.end()) break;
            
            cur = *it;
            if (cur.y > y + d) break; // Dừng lại nếu điểm có tung độ lớn hơn y + d
            
            if (cur.x < x - d) {
                T.erase(it);
                continue;
            } // Xóa điểm nếu điểm này có hoành độ bé hơn x - d
            
            
            if (distance(p, cur) < squared_d) {
                squared_d = distance(p, cur);
                res_id1 = id; res_id2 = cur.id;
            } // Gán đáp án mới nếu tìm được d nhỏ hơn
        }
        
        T.insert(p); // Thêm điểm hiện tại vào T
    }
    
    if (res_id1 > res_id2) swap(res_id1, res_id2);
    cout << res_id1 << " " << res_id2 << " ";
    cout << fixed << setprecision(6) << sqrt(squared_d);
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