/*
ID: henrikh1
TASK: crypt1
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

set<int> used;

bool check(int n, int len) {
  string num = to_string(n);
  while (n > 0) {
    if (!used.count(n % 10)) {
      return false;
    }
    n /= 10;
  }
  return num.size() == len;
}

int main() {
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");
  int n;
  fin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    fin >> d[i];
    used.insert(d[i]);
  }
  int ans = 0;
  for (int i = 100; i < 1000; i++) {
    for (int j = 10; j < 100; j++) {
      int x = i * (j % 10);
      int y = i * (j / 10);
      int p = y * 10 + x;
      bool ok = check(i, 3) and check(j, 2) and check(x, 3) and
                check(y, 3) and check(p, 4);
      ans += ok;
    }
  }
  fout << ans << "\n";
  return 0;
}
