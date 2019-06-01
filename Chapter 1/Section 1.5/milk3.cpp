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

int pour(int f, int cf, int t, int ct) {
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
  amnt = pour(a, ca, b, cb);
  solve(a - amnt, b + amnt, c);
  amnt = pour(b, cb, a, ca);
  solve(a + amnt, b - amnt, c);
  amnt = pour(a, ca, c, cc);
  solve(a - amnt, b, c + amnt);
  amnt = pour(c, cc, a, ca);
  solve(a + amnt, b, c - amnt);
  amnt = pour(b, cb, c, cc);
  solve(a, b - amnt, c + amnt);
  amnt = pour(c, cc, b, cb);
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
  fout << endl;
  return 0;
}
