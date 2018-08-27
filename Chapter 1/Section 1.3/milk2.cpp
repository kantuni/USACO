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
  int milk = color[start] ? 1 : 0;
  int nomilk = color[start] ? 0 : 1;
  int tm = milk, tnm = nomilk;
  for (int i = start + 1; i < end; i++) {
    if (color[i] > 0) {
      if (color[i - 1] == 0) {
        milk = 0;
      }
      milk++;
    } else {
      if (color[i - 1] > 0) {
        nomilk = 0;
      }
      nomilk++;
    }
    tm = max(tm, milk);
    tnm = max(tnm, nomilk);
  }
  fout << tm << " " << tnm << "\n";
  return 0;
}
