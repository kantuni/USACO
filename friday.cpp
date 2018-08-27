/*
ID: henrikh1
TASK: friday
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int din[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int mlen(int m, int y) {
  bool leap = y % 400 == 0 or (y % 4 == 0 and y % 100 != 0);
  return (m == 1) ? din[m] + leap : din[m];
}

int main() {
  ifstream fin("friday.in");
  ofstream fout("friday.out");
  int n;
  fin >> n;
  vector<int> f(7, 0);
  // Jan 13, 1900 was Saturday.
  int dow = 0;
  for (int y = 1900; y < 1900 + n; y++) {
    for (int m = 0; m < 12; m++) {
      f[dow]++;
      dow = (dow + mlen(m, y)) % 7;
    }
  }
  for (int i = 0; i < f.size(); i++) {
    fout << f[i];
    if (i != f.size() - 1) {
      fout << " ";
    }
  }
  fout << "\n";
  return 0;
}
