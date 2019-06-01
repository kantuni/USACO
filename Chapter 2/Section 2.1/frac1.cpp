/*
ID: henrikh1
TASK: frac1
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

struct Fraction {
  int num, denom;

  bool operator < (Fraction f) const {
    return num * f.denom < f.num * denom;
  }
};

set<Fraction> memo;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

void solve(int num, int denom, int n) {
  if (num <= denom) {
    int d = gcd(num, denom);
    Fraction f = {num / d, denom / d};
    if (!memo.count(f)) {
      memo.insert(f);
    }
    solve(num + 1, denom, n);
  } else if (denom < n) {
    solve(1, denom + 1, n);
  }
}

int main() {
  ifstream fin("frac1.in");
  ofstream fout("frac1.out");
  int n;
  fin >> n;
  solve(0, 1, n);
  for (auto f: memo) {
    fout << f.num << "/" << f.denom << endl;
  }
  return 0;
}
