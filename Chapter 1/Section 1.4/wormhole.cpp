/*
ID: henrikh1
TASK: wormhole
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> n_choose_two(string s) {
  vector<string> ans;
  if (s.size() == 2) {
    return {s};
  }
  for (int i = 1; i < s.size(); i++) {
    string sc = s;
    swap(sc[1], sc[i]);
    vector<string> rest = n_choose_two(sc.substr(2));
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
    fin >> c[i].second >> c[i].first;
  }
  sort(c.begin(), c.end());
  vector<int> next(n, -1);
  for (int i = 0; i < n - 1; i++) {
    if (c[i].first == c[i + 1].first) {
      next[i] = i + 1;
    }
  }
  string s;
  for (int i = 0; i < n; i++) {
    s += to_string(i);
  }
  int ans = 0;
  vector<string> combs = n_choose_two(s);
  for (int i = 0; i < combs.size(); i++) {
    string comb = combs[i];
    vector<int> redir(n);
    for (int j = 0; j < n; j += 2) {
      redir[comb[j] - '0'] = comb[j + 1] - '0';
      redir[comb[j + 1] - '0'] = comb[j] - '0';
    }
    bool loop = false;
    for (int j = 0; !loop and j < n; j++) {
      vector<int> color(n, 0);
      int curr = j;
      while (next[curr] != -1) {
        if (color[curr] == 1) {
          loop = true;
          break;
        }
        color[curr] = 1;
        curr = redir[next[curr]];
      }
    }
    ans += loop;
  }
  cout << ans << "\n";
  return 0;
}
