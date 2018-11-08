/*
ID: henrikh1
TASK: sort3
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");
  int n;
  fin >> n;
  vector<int> a(n), color(n);
  for (int i = 0; i < n; i++) {
    fin >> a[i];
  }
  vector<int> b(a);
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      color[i] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (color[i] == 1) continue;
    for (int j = i + 1; j < n; j++) {
      if (color[j] == 1) continue;
      if (a[i] == b[j] and a[j] == b[i]) {
        swap(a[i], a[j]);
        color[i] = color[j] = 1;
        ans++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (color[i] == 1) continue;
    for (int j = 0; j < n; j++) {
      if (color[j] == 1) continue;
      for (int k = 0; k < n; k++) {
        if (color[k] == 1) continue;
        if (a[i] == b[j] and a[j] == b[k] and a[k] == b[i]) {
          swap(a[i], a[j]);
          swap(a[i], a[k]);
          color[i] = color[j] = color[k] = 1;
          ans += 2;
        }
      }
    }
  }
  fout << ans << "\n";
  return 0;
}
