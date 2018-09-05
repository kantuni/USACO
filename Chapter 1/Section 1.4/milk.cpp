/*
ID: henrikh1
TASK: milk
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  int n, m;
  fin >> n >> m;
  if (n == 0 or m == 0) {
    fout << "0\n";
    return 0;
  }
  vector<pair<int, int>> farmers(m);
  for (int i = 0; i < m; i++) {
    fin >> farmers[i].first >> farmers[i].second;
  }
  sort(farmers.begin(), farmers.end());
  int ans = 0;
  for (int i = 0; n > 0 and i < m; i++) {
    int q = min(n, farmers[i].second);
    ans += farmers[i].first * q;
    n -= q;
  }
  fout << ans << "\n";
  return 0;
}