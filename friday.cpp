/*
ID: henrikh1
TASK: friday
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("friday.in");
  ofstream fout("friday.out");
  int n;
  fin >> n;
  vector<int> days(12, 31);
  days[3] = days[5] = days[8] = days[10] = 30;
  vector<int> f(7, 0);
  int start = 1;
  for (int y = 1900; y < 1900 + n; y++) {
    bool leap = y % 400 == 0 or (y % 4 == 0 and y % 100 != 0);
    days[1] = leap ? 29 : 28; 
    for (int m = 0; m < 12; m++) {
      for (int d = 0; d < days[m]; d++) {
        if (d == 12) {
          f[start]++;
        }
        start = (start + 1) % 7;
      }
    }
  }
  fout << f[6] << " ";
  for (int i = 0; i < 6; i++) {
    fout << f[i];
    if (i != 5) {
      fout << " ";
    }
  }
  fout << "\n";
  return 0;
}
