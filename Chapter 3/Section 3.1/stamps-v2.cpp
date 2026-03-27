/*
ID: henrikh1
TASK: stamps
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");
  int k, n;
  fin >> k >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    fin >> c[i];
  }
  sort(c.begin(), c.end());
  const int INF = 1e9;
  vector<int> dp(k * c.back() + 2, INF);
  dp[0] = 0;
  for (int i = 1; i < dp.size(); i++) {
    int res = INF;
    for (auto ci: c) {
      if (i - ci < 0) {
        break;
      }
      res = min(res, dp[i - ci] + 1);
    }
    dp[i] = res;
  }
  for (int i = 1; i < dp.size(); i++) {
    if (dp[i] > k) {
      fout << i - 1 << "\n";
      break;
    }
  }
  return 0;
}
