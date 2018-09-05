/*
ID: henrikh1
TASK: wormhole
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> combs(string s) {
  vector<string> ans;
  if (s.size() == 2) {
    return {s};
  }
  for (int i = 1; i < s.size(); i++) {
    string sc = s;
    swap(sc[1], sc[i]);
    vector<string> rest = combs(sc.substr(2));
    for (int j = 0; j < rest.size(); j++) {
      ans.push_back(
        string(1, sc[0]) + 
        string(1, sc[1]) + 
        rest[j]
      );
    }
  }
  return ans;
}

int main() {
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");
  int n;
  fin >> n;
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; i++) {
    fin >> c[i].first >> c[i].second;
  }
  string s;
  for (int i = 0; i < n; i++) {
    s += to_string(i);
  }
  int ans = 0;
  vector<string> res = combs(s);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "\n";
    // TODO: the check is incorrect
    bool loop = false;
    for (int j = 0; j < n; j += 2) {
      auto p1 = c[res[i][j] - '0'];
      auto p2 = c[res[i][j + 1] - '0'];
      if (p1.second == p2.second) {
        loop = true;
        break;
      }
    }
    // TODO: find (AC),(BD) pattern
    for (int j = 0; j < n - 2; j += 2) {
      auto p1 = c[res[i][j] - '0'];
      auto p2 = c[res[i][j + 1] - '0'];
      auto p3 = c[res[i][j + 2] - '0'];
      auto p4 = c[res[i][j + 3] - '0'];
      bool l1 = p1.second == p3.second and 
                p2.second == p4.second and
                p4.second < p1.second;
      bool l2 = p2.second == p3.second and
                p1.second == p4.second and
                p4.second < p2.second;
      if (l1 or l2) {
        loop = true;
        break;
      }
    }
    ans += loop;
  }
  fout << ans << "\n";
  return 0;
}
