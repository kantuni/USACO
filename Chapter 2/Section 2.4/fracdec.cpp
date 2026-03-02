/*
ID: henrikh1
TASK: fracdec
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
map<int, pair<int, char>> g;
map<int, int> color;
int cs = -1, cnt = 0;

void print(char c) {
  // Where does this come from?
  if (c == '\0') {
    return;
  }
  fout << c;
  cnt++;
  if (cnt % 76 == 0) {
    fout << "\n";
    cnt = 0;
  }
}

void dfs(int u) {
  color[u] = 1;
  auto [v, q] = g[u];
  if (color[v] == 0) {
    if (v == cs) {
      print('(');
    }
    print(q);
    dfs(v);
  } else {
    print(q);
    if (cs != -1) {
      print(')');
    }
  }
}

int main() {
  int n, d;
  fin >> n >> d;
  int a = n / d;
  int nc = n - a * d;
  while (nc % d > 0) {
    int rem = nc * 10 % d;
    if (g.count(nc) > 0) {
      cs = rem;
      break;
    }
    char q = (nc * 10 / d) + '0';
    g[nc] = {rem, q};
    nc = rem;
  }
  string sa = to_string(a);
  for (auto c: sa) {
    print(c);
  }
  print('.');
  int u = n - a * d;
  if (u % d == 0) {
    print('0');
  } else if (cs == u) {
    print('(');
    print(g[u].second);
    print(')');
  } else {
    dfs(u);
  }
  if (cnt > 0) {
    fout << "\n";
  }
  return 0;
}
