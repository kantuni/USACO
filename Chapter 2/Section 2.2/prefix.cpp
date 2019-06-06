/*
ID: henrikh1
TASK: prefix
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> ps;
map<int, int> memo;

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
  stack<pair<int, int>> s;
  s.push({start, 0});
  int ans = 0;
  while (!s.empty()) {
    auto cur = s.top(); s.pop();
    int from = cur.first, len = cur.second;
    if (memo[from] > 0) {
      continue;
    }
    for (auto p: ps) {
      if (prefix(from, p)) {
        int skip = p.size();
        s.push({from + skip, skip + len});
        ans = max(ans, skip + len);
      }
    }
    memo[from] = ans;
  }
  return ans;
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
