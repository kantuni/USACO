/*
ID: henrikh1
TASK: comehome
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  ifstream fin("comehome.in");
  ofstream fout("comehome.out");
  map<char, map<char, int>> g;
  int p;
  fin >> p;
  while (p--) {
    char u, v;
    int d;
    fin >> u >> v >> d;
    if (u == v) {
      continue;
    }
    if (g[u].count(v) == 0 and g[v].count(u) == 0) {
      g[u][v] = g[v][u] = d;
    } else if (g[u].count(v) > 0) {
      int mind = min(g[u][v], d);
      g[u][v] = g[v][u] = mind;
    } else if (g[v].count(u) > 0) {
      int mind = min(g[v][u], d);
      g[u][v] = g[v][u] = mind;
    }
  }
  map<char, int> dist;
  for (auto [u, _]: g) {
    dist[u] = INF;
  }
  dist['Z'] = 0;
  priority_queue<pair<int, char>> pq;
  pq.push({0, 'Z'});
  while (!pq.empty()) {
    auto [_, u] = pq.top(); pq.pop();
    for (auto [v, dv]: g[u]) {
      if (dist[v] > dist[u] + g[u][v]) {
        dist[v] = dist[u] + g[u][v];
        pq.push({-dist[v], v});
      }
    }
  }
  int mind = INF;
  char minl = '_';
  for (auto c = 'A'; c < 'Z'; c++) {
    if (dist.count(c) > 0 and dist[c] < mind) {
      mind = dist[c];
      minl = c;
    }
  }
  fout << minl << " " << mind << "\n";
  return 0;
}
