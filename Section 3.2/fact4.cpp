/*
ID: henrikh1
TASK: fact4
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("fact4.in");
  ofstream fout("fact4.out");
  int n;
  fin >> n;
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    int j = i;
    int cnt = 0;
    while (j % 5 == 0) {
      j /= 5;
      cnt++;
    }
    while (cnt--) {
      ans /= 2;
    }
    ans *= j;
    while (ans % 10 == 0) {
      ans /= 10;
    }
    ans %= 10000;
  }
  fout << ans % 10 << "\n";
  return 0;
}
