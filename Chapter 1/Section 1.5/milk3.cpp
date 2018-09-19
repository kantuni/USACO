/*
ID: henrikh1
TASK: milk3
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

set<string> memo;
set<int> ans;
int ca, cb, cc;

string hsh(int a, int b, int c) {
  return to_string(a) + "," + 
         to_string(b) + "," + 
         to_string(c);
}

int poor(int f, int cf, int t, int ct) {
  int left = ct - t;
  return min(f, left);
}

void solve(int a, int b, int c) {
  string h = hsh(a, b, c);
  if (memo.count(h)) {
    return;
  }
  memo.insert(h);
  if (a == 0) {
    ans.insert(c);
  }
  int amnt;
  // a->b
  amnt = poor(a, ca, b, cb);
  solve(a - amnt, b + amnt, c);
  // b->a
  amnt = poor(b, cb, a, ca);
  solve(a + amnt, b - amnt, c);
  // a->c
  amnt = poor(a, ca, c, cc);
  solve(a - amnt, b, c + amnt);
  // c->a
  amnt = poor(c, cc, a, ca);
  solve(a + amnt, b, c - amnt);
  // b->c
  amnt = poor(b, cb, c, cc);
  solve(a, b - amnt, c + amnt);
  // c->b
  amnt = poor(c, cc, b, cb);
  solve(a, b + amnt, c - amnt);
}

int main() {
  ifstream fin("milk3.in");
  ofstream fout("milk3.out");
  fin >> ca >> cb >> cc;
  solve(0, 0, cc);
  for (auto it = ans.begin(); it != ans.end(); it++) {
    fout << *it;
    if (next(it) != ans.end()) {
      fout << " ";
    }
  }
  fout << "\n";
  return 0;
}
