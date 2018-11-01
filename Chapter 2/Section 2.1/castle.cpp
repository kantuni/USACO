#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mp;
vector<vector<int>> color;

int dfs(int i, int j, int comp) {
  if (color[i][j] != 0) {
    return 0;
  }
  color[i][j] = comp;
  int size = 0;
  int cell = mp[i][j];
  if (cell < 8) {
    size += dfs(i + 1, j, comp);
  }
  cell = (cell < 8) ? cell : cell - 8;
  if (cell < 4) {
    size += dfs(i, j + 1, comp);
  }
  cell = (cell < 4) ? cell : cell - 4;
  if (cell < 2) {
    size += dfs(i - 1, j, comp);
  }
  cell = (cell < 2) ? cell : cell - 2;
  if (cell < 1) {
    size += dfs(i, j - 1, comp);
  }
  cell = (cell < 1) ? cell : cell - 1;
  return size + 1;
}

int main() {
  ifstream fin("castle.in");
  // ofstream fout("castle.out");
  int n, m;
  fin >> m >> n;
  mp.assign(n, vector<int>(m));
  color.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fin >> mp[i][j];
    }
  }
  int comp = 1;
  int mx = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (color[i][j] == 0) {
        mx = max(mx, dfs(i, j, comp));
        comp++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << color[i][j] << " ";
    }
    cout << "\n";
  }
  cout << comp - 1 << "\n";
  cout << mx << "\n";
  return 0;
}
