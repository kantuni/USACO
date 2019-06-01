/*
ID: henrikh1
TASK: castle
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mp;
vector<vector<int>> color;

int dfs(int i, int j, int comp) {
  if (color[i][j] != 0) {
    return 0;
  }
  color[i][j] = comp;
  int cell = mp[i][j];
  int size = 0;
  size += (cell & 8) == 0 ? dfs(i + 1, j, comp) : 0;
  size += (cell & 4) == 0 ? dfs(i, j + 1, comp) : 0;
  size += (cell & 2) == 0 ? dfs(i - 1, j, comp) : 0;
  size += (cell & 1) == 0 ? dfs(i, j - 1, comp) : 0;
  return size + 1;
}

int main() {
  ifstream fin("castle.in");
  ofstream fout("castle.out");
  int n, m;
  fin >> m >> n;
  mp.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fin >> mp[i][j];
    }
  }
  int comp = 1;
  int mr = -1;
  color.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (color[i][j] == 0) {
        mr = max(mr, dfs(i, j, comp));
        comp++;
      }
    }
  }
  fout << comp - 1 << endl;
  fout << mr << endl;
  int rx, ry, rs;
  int nmr = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int s = pow(2, k);
        if (i == 0 and s == 2) continue;
        if (j == 0 and s == 1) continue;
        if (i == n - 1 and s == 8) continue;
        if (j == m - 1 and s == 4) continue;
        if (mp[i][j] & s) {
          mp[i][j] -= s;
          if (s == 1) {
            mp[i][j - 1] -= 4;
          } else if (s == 2) {
            mp[i - 1][j] -= 8;
          } else if (s == 4) {
            mp[i][j + 1] -= 1;
          } else {
            mp[i + 1][j] -= 2;
          }
          comp = 1;
          mr = -1;
          color.assign(n, vector<int>(m));
          for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
              if (color[r][c] == 0) {
                mr = max(mr, dfs(r, c, comp));
                comp++;
              }
            }
          }
          if (mr > nmr) {
            rx = i;
            ry = j;
            rs = s;
            nmr = mr;
          } else if (mr == nmr) {
            bool fw = j < ry;
            bool fs = j == ry and i > rx;
            bool nbe = j == ry and i == rx and rs > s;
            if (fw or fs or nbe) {
              rx = i;
              ry = j;
              rs = s;
            }
          }
          mp[i][j] += s;
          if (s == 1) {
            mp[i][j - 1] += 4;
          } else if (s == 2) {
            mp[i - 1][j] += 8;
          } else if (s == 4) {
            mp[i][j + 1] += 1;
          } else {
            mp[i + 1][j] += 2;
          }
        }
      }
    }
  }
  char side = (rs == 1) ? 'W' : (rs == 2) ? 'N' : (rs == 4) ? 'E' : 'S';
  fout << nmr << endl;
  fout << rx + 1 << " " << ry + 1 << " " << side << endl;
  return 0;
}
