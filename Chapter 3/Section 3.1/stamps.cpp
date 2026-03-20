/*
ID: henrikh1
TASK: stamps 
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int);
int remember(int);

const int INF = 1e9;
int k, n;
vector<int> s, memo;

int solve(int m) {
  if (m == 0) {
    return 0;
  }
  int res = INF;
  for (int i = 0; i < n; i++) {
    if (m - s[i] < 0) {
      break;
    }
    int best = remember(m - s[i]);
    if (best == INF or best >= k) {
      continue;
    }
    res = min(res, 1 + best);
  }
  return res;
}

int remember(int m) {
  if (memo[m] == -1) {
    memo[m] = solve(m);
  }
  return memo[m];
}

int main() {
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");
  fin >> k >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    fin >> s[i];
  }
  sort(s.begin(), s.end());
  memo.assign(k * s[s.size() - 1] + 1, -1);
  int m = 1;
  while (solve(m) <= k) {
    m++;
  }
  fout << m - 1 << "\n";
  return 0;
}
