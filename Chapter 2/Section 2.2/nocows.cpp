/*
ID: henrikh1
TASK: nocows
LANG: C++14
*/

#include <bits/stdc++.h>
#define P 9901
using namespace std;

map<int, map<int, int>> memo;

int solve(int n, int k) {
  if (n < 3 or k < 2) return 0;
  if (memo[n].count(k) == 0) {
    memo[n][k] = solve(n - 2, k - 1) * 2;
  }
  return memo[n][k] % P;
}

int main() {
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");
  int n, k;
  fin >> n >> k;
  for (int i = 0; i <= k; i++) {
    memo[(1 << i) - 1][i] = 1;
  }
  int ans = solve(n, k);
  fout << ans << endl;
  return 0;
}
