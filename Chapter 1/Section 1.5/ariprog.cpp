/*
ID: henrikh1
TASK: ariprog
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");
  int n, m;
  fin >> n >> m;
  vector<int> bisq(2 * m * m + 1);
  for (int p = 0; p <= m; p++) {
    for (int q = 0; q <= m; q++) {
      bisq[p * p + q * q] = 1;
    }
  }
  vector<pair<int, int>> ans;
  for (int a = 0; a <= 2 * m * m - 2; a++) {
    for (int b = 1; a + (n - 1) * b <= 2 * m * m; b++) {
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (bisq[a + i * b] == 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans.push_back({b, a});
      }
    }
  }
  if (ans.size() == 0) {
    fout << "NONE" << endl;
  } else {
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
      fout << ans[i].second << " " << ans[i].first << endl;
    }
  }
  return 0;
}
