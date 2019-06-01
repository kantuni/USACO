/*
ID: henrikh1
TASK: combo
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a, b, c;
int x, y, z;

bool crack(int i, int j, int k) {
  vector<int> jdiff = {
    abs(a - i),
    abs(b - j),
    abs(c - k)
  };
  bool john = true;
  for (int i = 0; i < 3; i++) {
    if (jdiff[i] > 2 and jdiff[i] < n - 2) {
      john = false;
      break;
    }
  }
  vector<int> mdiff = {
    abs(x - i),
    abs(y - j),
    abs(z - k)
  };
  bool master = true;
  for (int i = 0; i < 3; i++) {
    if (mdiff[i] > 2 and mdiff[i] < n - 2) {
      master = false;
      break;
    }
  }
  return john or master;
}

int main() {
  ifstream fin("combo.in");
  ofstream fout("combo.out");
  fin >> n;
  fin >> a >> b >> c;
  fin >> x >> y >> z;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        ans += crack(i, j, k);
      }
    }
  }
  fout << ans << endl;
  return 0;
}
