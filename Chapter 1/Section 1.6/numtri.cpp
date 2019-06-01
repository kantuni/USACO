/*
ID: henrikh1
TASK: numtri
LANG: C++14
*/

#include <bits/stdc++.h>
#define MAX_N 1005
using namespace std;

int memo[MAX_N][MAX_N];
int t[MAX_N][MAX_N];

int solve(int i, int j, int n) {
  if (i == n or j > i + 1) {
    return 0;
  }
  if (memo[i + 1][j] == -1) {
    memo[i + 1][j] = solve(i + 1, j, n);
  }
  if (memo[i + 1][j + 1] == -1) {
    memo[i + 1][j + 1] = solve(i + 1, j + 1, n);
  }
  return t[i][j] + max(memo[i + 1][j], memo[i + 1][j + 1]); 
}

int main() {
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");
  memset(memo, -1, sizeof memo);
  int n;
  fin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      fin >> t[i][j];
    }
  }
  fout << solve(0, 0, n) << endl;
  return 0;
}
