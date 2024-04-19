#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[MAXN];
vector<int> dist1, distN;

void dijkstra1(int s) {
  dist1.assign(n + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist1[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (dist1[u] < pq.top().first) continue;
    for (auto v : adj[u]) {
      int w = v.second;
      if (dist1[v.first] > dist1[u] + w) {
        dist1[v.first] = dist1[u] + w;
        pq.push({dist1[v.first], v.first});
      }
    }
  }
}

void dijkstraN(int s) {
  distN.assign(n + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  distN[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (distN[u] < pq.top().first) continue;
    for (auto v : adj[u]) {
      int w = v.second;
      if (distN[v.first] > distN[u] + w) {
        distN[v.first] = distN[u] + w;
        pq.push({distN[v.first], v.first});
      }
    }
  }
}

bool isCriticalPath(int i) {
  return dist1[i] + distN[i] == dist1[n] && dist1[i] <= dist1[n] && distN[i] <= distN[n];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dijkstra1(1);
  dijkstraN(n);

  int critical_paths = 0;
  for (int i = 1; i <= n; i++) {
    if (isCriticalPath(i)) {
      critical_paths++;
    }
  }

  cout << critical_paths << endl;
  return 0;
}
