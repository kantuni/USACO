/*
ID: henrikh1
TASK: sort3
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
vector<int> color;

int dfs(int start, int i) {
  color[i] = 1;
  if (b[i] == start) {
    return 0;
  }
  for (int j = 0; j < a.size(); j++) {
    if (color[j] == 0 and a[j] == b[i]) {
      return 1 + dfs(start, j);
    }
  }
  return 0;
}

int main() {
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");
  int n;
  fin >> n;
  a.resize(n);
  color.resize(n);
  for (int i = 0; i < n; i++) {
    fin >> a[i];
  }
  b = a;
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      ans += dfs(a[i], i);
    }
  }
  fout << ans << "\n";
  return 0;
}
