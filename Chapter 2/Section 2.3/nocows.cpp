/*
ID: henrikh1
TASK: nocows
LANG: C++14
*/

// WA
#include <bits/stdc++.h>
#define P 9901
using namespace std;

map<int, map<int, int>> memo;

int solve(int n, int k) {
  if (n < 3 or k < 2) return 0;
  if (memo[n].count(k) == 0) {
    int c1 = solve(n - 2, k) / 2;
    int c2 = solve(n - 2, k - 1) * (n - pow(2, k - 2) - 1);
    memo[n][k] = c1 + c2;
  }
  return memo[n][k] % P;
}

int main() {
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    memo[(1 << i) - 1][i] = 1;
  }
  int ans = solve(n, k);
  cout << ans << endl;
  return 0;
}
