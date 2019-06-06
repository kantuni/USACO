/*
ID: henrikh1
TASK: prefix
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> ps;

bool prefix(int start, string p) {
  if (p.size() > s.size() + start) {
    return false;
  }
  for (int i = 0; i < p.size(); i++) {
    if (p[i] != s[start + i]) {
      return false;
    }
  }
  return true;
}

int solve(int start) {
  int mx = 0;
  for (auto p: ps) {
    if (prefix(start, p)) {
      int skip = p.size();
      mx = max(mx, skip + solve(start + skip));
    }
  }
  return mx;
}

int main() {
  ifstream fin("prefix.in");
  ofstream fout("prefix.out");
  while (true) {
    string p;
    fin >> p;
    if (p == ".") {
      break;
    }
    ps.push_back(p);
  }
  string line;
  while (getline(fin, line)) {
    s.append(line);
  }
  fout << solve(0) << endl;
  return 0;
}
