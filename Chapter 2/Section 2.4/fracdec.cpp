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

void print(string s) {
  for (auto c: s) {
    fout << c;
    cnt++;
    if (cnt % 76 == 0) {
      fout << "\n";
      cnt = 0;
    }
  }
}

void dfs(int u) {
  color[u] = 1;
  auto [v, q] = g[u];
  if (color[v] == 0) {
    if (v == cs) {
      print("(");
    }
    print(string(1, q));
    dfs(v);
  } else {
    // Ignore 0 -> 0 loop
    if (v != 0) {
      print(string(1, q));
    }
    if (cs != -1) {
      print(")");
    }
  }
}

int main() {
  int n, d;
  fin >> n >> d;
  int a = n / d;
  int nc = n % d;
  while (nc % d > 0) {
    int rem = (nc * 10) % d;
    if (g.count(nc) > 0) {
      cs = rem;
      break;
    }
    char q = (nc * 10 / d) + '0';
    g[nc] = {rem, q};
    nc = rem;
  }
  print(to_string(a));
  print(".");
  int u = n % d;
  if (u % d == 0) {
    print("0");
  } else if (cs == u) {
    auto [_, q] = g[u];
    print("(" + string(1, q) + ")");
  } else {
    dfs(u);
  }
  if (cnt > 0) {
    print("\n");
  }
  return 0;
}
