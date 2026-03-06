/*
ID: henrikh1
TASK: agrinet
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("agrinet.in");
  ofstream fout("agrinet.out");
  int n;
  fin >> n;
  int g[n][n];
  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      fin >> g[u][v];
    }
  }
  priority_queue<pair<int, int>> pq;
  vector<int> color(n, 0);
  pq.push({0, 0});
  int ans = 0, cnt = 0;
  while (cnt < n) {
    auto [cost, u] = pq.top(); pq.pop();
    if (color[u] == 1) {
      continue;
    }
    color[u] = 1;
    ans += -cost;
    cnt++;
    for (int v = 0; v < n; v++) {
      if (color[v] == 1 or g[u][v] == 0) {
        continue;
      }
      pq.push({-g[u][v], v});
    }
  }
  fout << ans << "\n";
  return 0;
}
