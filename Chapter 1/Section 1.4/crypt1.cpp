/*
ID: henrikh1
TASK: crypt1
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

set<int> used;

bool crypta(int n, int len) {
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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          for (int m = 0; m < n; m++) {
            int x = d[i] * 100 + d[j] * 10 + d[k];
            int y = 10 * d[l] + d[m];
            int p1 = x * d[m];
            int p2 = x * d[l];
            int p = p2 * 10 + p1;
            if (crypta(p1, 3) and crypta(p2, 3) and crypta(p, 4)) {
              ans++;
            }
          }
        }
      }
    }
  }
  fout << ans << "\n";
  return 0;
}
