/*
ID: henrikh1
TASK: hamming
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int hamming(int a, int b) {
  int x = a xor b;
  int dist = 0;
  while (x > 0) {
    dist += x % 2;
    x /= 2;
  }
  return dist;
}

int main() {
  ifstream fin("hamming.in");
  ofstream fout("hamming.out");
  int n, b, d;
  fin >> n >> b >> d;
  vector<int> ans;
  for (int i = 0; ans.size() < n; i++) {
    bool ok = true;
    for (int j = 0; j < ans.size(); j++) {
      int dist = hamming(i, ans[j]);
      if (dist < d) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans.push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    fout << ans[i];
    bool tenth = (i + 1) % 10 == 0;
    bool last = i == n - 1;
    if (tenth or last) {
      fout << "\n";
    } else {
      fout << " ";
    }
  }
  return 0;
}
