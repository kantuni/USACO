/*
ID: henrikh1
TASK: sprime
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(1. * n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve(int p, int curr, int n) {
  if (curr == 1) {
    solve(2, curr + 1, n);
    solve(3, curr + 1, n);
    solve(5, curr + 1, n);
    solve(7, curr + 1, n);
  } else if (curr < n + 1) {
    for (int i = 0; i < 10; i++) {
      int super = p * 10 + i;
      if (prime(super)) {
        solve(super, curr + 1, n);
      }
    }
  } else {
    fout << p << "\n";
  }
}

int main() {
  int n;
  fin >> n;
  solve(0, 1, n);
  return 0;
}
