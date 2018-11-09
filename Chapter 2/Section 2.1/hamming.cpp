/*
ID: henrikh1
TASK: hamming
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int n, b, d;

int hamming(int a, int b) {
  int x = a xor b;
  int dist = 0;
  while (x > 0) {
    dist += x % 2;
    x /= 2;
  }
  return dist;
}

void dfs(int i) {
  ans.push_back(i);
  if (ans.size() == n) {
    return;
  }
  for (int j = i; true; j++) {
    int dist = hamming(i, j);
    if (dist >= d) {
      dfs(j);
      break;
    }
  }
}

int main() {
  ifstream fin("hamming.in");
  ofstream fout("hamming.out");
  fin >> n >> b >> d;
  dfs(0);
  for (int i = 0; i < n; i++) {
    fout << ans[i];
    bool tenth = i > 0 and i % 9 == 0;
    bool last = i == n - 1;
    if (tenth or last) {
      fout << "\n";
    } else {
      fout << " ";
    }
  }
  return 0;
}
