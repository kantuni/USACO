/*
ID: henrikh1
TASK: numtri
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
map<string, int> memo;

string hsh(int i, int j) {
  return to_string(i) + "," + to_string(j);
}

int solve(int i, int j) {
  if (i == t.size() or j > i + 1) {
    return 0;
  }
  string left = hsh(i + 1, j);
  string right = hsh(i + 1, j + 1);
  memo[left] = !memo.count(left) ? solve(i + 1, j) : memo[left];
  memo[right] = !memo.count(right) ? solve(i + 1, j + 1) : memo[right];
  return t[i][j] + max(memo[left], memo[right]);
}

int main() {
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");
  int n;
  fin >> n;
  t.resize(n);
  for (int i = 0; i < n; i++) {
    t[i].resize(i + 1);
    for (int j = 0; j < i + 1; j++) {
      fin >> t[i][j];
    }
  }
  fout << solve(0, 0) << "\n";
  return 0;
}
