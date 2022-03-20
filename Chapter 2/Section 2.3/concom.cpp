/*
ID: henrikh1
TASK: concom
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> g;
map<int, int> own;
set<int> visited;

void dfs(int u) {
  visited.insert(u);
  for (auto [v, p]: g[u]) {
    own[v] += p;
    if (visited.count(v) == 0 and own[v] > 50) {
      dfs(v);
    }
  }
}

int main() {
  ifstream fin("concom.in");
  ofstream fout("concom.out");
  int n;
  fin >> n;
  while (n--) { 
    int i, j, p;
    fin >> i >> j >> p;
    g[i].push_back({j, p});
  }
  for (auto [u, _]: g) {
    dfs(u);
    for (auto [v, p]: own) {
      if (u != v and p > 50) {
        fout << u << " " << v << endl; 
      }
    }
    own.clear();
    visited.clear();
  }
  return 0;
}
