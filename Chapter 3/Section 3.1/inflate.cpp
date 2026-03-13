/*
ID: henrikh1
TASK: inflate 
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("inflate.in");
  ofstream fout("inflate.out");
  int m, n;
  fin >> m >> n;
  vector<pair<int, int>> ps(n);
  for (int i = 0; i < n; i++) {
    int p, t;
    fin >> p >> t;
    ps[i] = {p, t};
  }
  vector<int> prv(m + 1), cur(m + 1);
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      auto [p, t] = ps[i - 1];
      cur[j] = max(prv[j], j >= t ? p + cur[j - t] : 0);
    }
    prv = cur;
  }
  int ans = cur[m];
  fout << ans << "\n";
  return 0;
}
