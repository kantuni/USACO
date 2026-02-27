/*
ID: henrikh1
TASK: fracdec
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
map<int, map<int, int>> g;
map<int, int> color;
int cs = -1, cnt = 0;

void print(const string& s) {
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
  for (auto [v, num]: g[u]) {
    if (color[v] == 0) {
      if (v == cs) {
        print("(");
      }
      cout << num;
      print(to_string(num));
      dfs(v);
    } else {
      fout << num;
      print(to_string(num));
      print(")");
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
    if (g[nc].count(rem) > 0) {
      cs = rem;
      break;
    }
    g[nc][rem] = nc * 10 / d;
    nc = rem;
  }
  print(to_string(a));
  print(".");
  int u = n - a * d;
  if (u % d == 0) {
    print("0");
  } else if (cs == u) {
    print("(");
    print(to_string(g[u][u]));
    print(")");
  } else {
    cout << "before" << "\n";
    dfs(u);
    cout << "after" << "\n";
  }
  if (cnt > 0) {
    fout << "\n";
  }
  return 0;
}
