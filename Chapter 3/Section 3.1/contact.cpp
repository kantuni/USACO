/*
ID: henrikh1
TASK: contact 
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("contact.in");
  ofstream fout("contact.out");
  int a, b, n;
  fin >> a >> b >> n;
  string s, si;
  while (fin >> si) {
    s += si;
  }
  map<string, int> memo;
  for (int k = a; k <= b; k++) {
    for (int i = 0; i <= (int) (s.size()) - k; i++) {
      string ss = s.substr(i, k);
      memo[ss] += 1;
    }
  }
  map<int, vector<string>, greater<int>> freq;
  for (auto [p, cnt]: memo) {
    freq[cnt].push_back(p);
  }
  for (auto [cnt, ps]: freq) {
    if (n == 0) {
      break;
    }
    fout << cnt << "\n";
    sort(ps.begin(), ps.end(), [](const string& s1, const string& s2) {
      if (s1.size() == s2.size()) {
        return s1 < s2;
      }
      return s1.size() < s2.size();
    });
    for (int i = 0; i < ps.size(); i++) {
      fout << ps[i];
      if (i == ps.size() - 1) {
        continue;
      }
      if (i > 0 and i % 6 == 5) {
        fout << "\n";
      } else {
        fout << " ";
      }
    }
    fout << "\n";
    n--;
  }
  return 0;
}
