/*
ID: henrikh1
TASK: skidesign
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("skidesign.in");
  ofstream fout("skidesign.out");
  int n;
  fin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    fin >> h[i];
  }
  sort(h.begin(), h.end());
  int ans = -1;
  if (n == 1 or h[n - 1] - h[0] < 18) {
    ans = 0;
  } else {
    for (int i = 0; i < 84; i++) {
      int amnt = 0;
      for (int j = 0; j < n; j++) {
        if (h[j] < i or h[j] > i + 17) {
          int d1 = pow(h[j] - i, 2);
          int d2 = pow(h[j] - i - 17, 2);
          amnt += min(d1, d2);
        }
      }
      ans = (ans == -1) ? amnt : min(ans, amnt);
    }
  }
  fout << ans << "\n";
  return 0;
}
