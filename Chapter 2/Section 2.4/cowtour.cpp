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
  // Floyd-Warshall
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }
  double diam1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (D[i][j] != INF) {
        diam1 = max(diam1, D[i][j]);
      }
    }
  }
  vector<double> mxd(n);
  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      if (D[u][v] != INF) {
        mxd[u] = max(mxd[u], D[u][v]);
      }
    }
  }
  double diam2 = INF;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (color[i] != color[j]) {
        auto [xi, yi] = coords[i];
        auto [xj, yj] = coords[j];
        auto d = hypot(xi - xj, yi - yj);
        diam2 = min(diam2, mxd[i] + d + mxd[j]);
      }
    }
  }
  fout << fixed << setprecision(6);
  fout << max(diam1, diam2) << "\n";
  return 0;
}
