/*
ID: henrikh1
TASK: humble 
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("humble.in");
  ofstream fout("humble.out");
  int k, n;
  fin >> k >> n;
  vector<long long> p(k);
  set<long long> s;
  for (int i = 0; i < k; i++) {
    fin >> p[i];
    s.insert(p[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    auto mn = *begin(s);
    for (auto pi: p) {
      auto val = mn * pi;
      auto mx = *prev(end(s));
      if (s.size() <= n or val < mx) {
        s.insert(val);
      }
    }
    s.erase(mn);
  }
  auto ans = *begin(s);
  fout << ans << "\n";
  return 0;
}
