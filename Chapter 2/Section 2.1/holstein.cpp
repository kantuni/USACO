/*
ID: henrikh1
TASK: holstein
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("holstein.in");
  ofstream fout("holstein.out");
  int n;
  fin >> n;
  int v[n];
  for (int i = 0; i < n; i++) {
    fin >> v[i];
  }
  int m;
  fin >> m;
  int g[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      fin >> g[i][j];
    }
  }
  int ans = m, mi = pow(2, m) - 1;
  for (int i = 1; i < pow(2, m); i++) {
    bitset<15> b(i);
    vector<int> w(n);
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (b[j] == 1) {
        for (int k = 0; k < n; k++) {
          w[k] += g[j][k];
        }
        cnt++;
      }
    }
    bool ok = true;
    for (int k = 0; k < n; k++) {
      if (w[k] < v[k]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      if (ans > cnt) {
        ans = cnt;
        mi = i;
      } else if (ans == cnt) {
        mi = min(mi, i);
      }
    }
  }
  fout << ans;
  bitset<15> b(mi);
  for (int i = 0; i < m; i++) {
    if (b[i] == 1) {
      fout << " " << i + 1;
    }
  }
  fout << endl;
  return 0;
}
