/*
ID: henrikh1
TASK: milk2
LANG: C++14
*/

#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;

int main() {
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");
  int n;
  fin >> n;
  vector<int> color(MAXN, 0);
  int start = MAXN, end = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    fin >> l >> r;
    start = min(start, l);
    end = max(end, r);
    for (int j = l; j < r; j++) {
      color[j]++;
    }
  }
  int yes = color[start] ? 1 : 0;
  int no = color[start] ? 0 : 1;
  int ymax = yes, nmax = no;
  for (int i = start + 1; i < end; i++) {
    if (color[i] > 0) {
      if (color[i - 1] == 0) {
        yes = 0;
      }
      yes++;
    } else {
      if (color[i - 1] > 0) {
        no = 0;
      }
      no++;
    }
    ymax = max(ymax, yes);
    nmax = max(nmax, no);
  }
  fout << ymax << " " << nmax << "\n";
  return 0;
}
