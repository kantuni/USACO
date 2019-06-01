/*
ID: henrikh1
TASK: gift1
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");
  int n;
  fin >> n;
  vector<string> names(n);
  map<string, int> memo;
  for (int i = 0; i < n; i++) {
    fin >> names[i];
    memo[names[i]] = 0;
  }
  for (int i = 0; i < n; i++) {
    string giver;
    fin >> giver;
    int total, m;
    fin >> total >> m;
    if (m > 0) {
      memo[giver] += -m * (total / m);
    }
    for (int j = 0; j < m; j++) {
      string name;
      fin >> name;
      memo[name] += total / m;
    }
  }
  for (int i = 0; i < n; i++) {
    fout << names[i] << " " << memo[names[i]] << endl;
  }
  return 0;
}
