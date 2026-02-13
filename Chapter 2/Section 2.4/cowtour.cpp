/*
ID: henrikh1
TASK: cowtour
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;
int n;
vector<vector<int>> M;
vector<vector<double>> D;
vector<int> color;

void dfs(int u, int c) {
  color[u] = c;
  for (int v = 0; v < n; v++) {
    if (M[u][v] == 1 and color[v] == 0) {
      dfs(v, c);
    }
  }
}

double fw(vector<vector<double>> D) {
  double diam = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        if (D[i][j] != INF) {
          diam = max(diam, D[i][j]);
        }
      }
    }
  }
  return diam;
}

int main() {
  ifstream fin("cowtour.in");
  ofstream fout("cowtour.out");
  fin >> n;
  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    fin >> x >> y;
    coords[i] = {x, y};
  }
  M.assign(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      fin >> c;
      M[i][j] = c - '0';
    }
  }
  color.assign(n, 0);
  int c = 1;
  for (int u = 0; u < n; u++) {
    if (color[u] == 0) {
      dfs(u, c);
      c++;
    }
  }
  set<int> s1, s2;
  for (int u = 0; u < n; u++) {
    if (color[u] == 1) {
      s1.insert(u);
    } else {
      s2.insert(u);
    }
  }
  D.assign(n, vector<double>(n, INF));
  for (int u = 0; u < n; u++) {
    D[u][u] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (M[i][j] == 1) {
        auto [xi, yi] = coords[i];
        auto [xj, yj] = coords[j];
        D[i][j] = hypot(xi - xj, yi - yj);
      }
    }
  }
  double ans = INF;
  for (auto u: s1) {
    for (auto v: s2) {
      auto [xu, yu] = coords[u];
      auto [xv, yv] = coords[v];
      D[u][v] = hypot(xu - xv, yu - yv);
      ans = min(ans, fw(D));
      D[u][v] = INF;
    }
  }
  fout << fixed << setprecision(6);
  fout << ans << "\n";
  return 0;
}
