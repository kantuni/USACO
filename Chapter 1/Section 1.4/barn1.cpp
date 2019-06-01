/*
ID: henrikh1
TASK: barn1
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");
  int m, s, c;
  fin >> m >> s >> c;
  vector<int> stalls(c);
  for (int i = 0; i < c; i++) {
    fin >> stalls[i];  
  }
  sort(stalls.begin(), stalls.end());
  vector<int> diff(c - 1);
  multimap<int, int> memo;
  for (int i = 0; i < c - 1; i++) {
    diff[i] = stalls[i + 1] - stalls[i];
    memo.insert({diff[i], i});
  }
  set<int> breaks;
  for (auto it = memo.rbegin(); m > 1; it++, m--) {
    int index = (*it).second;
    breaks.insert(index);
  }
  int ans = 0;
  int curr = stalls[0];
  for (int i = 0; i < c; i++) {
    if (breaks.count(i)) {
      ans += stalls[i] - curr + 1;
      curr = stalls[i + 1];
    }
  }
  ans += stalls[c - 1] - curr + 1;
  fout << ans << endl;
  return 0;
}
