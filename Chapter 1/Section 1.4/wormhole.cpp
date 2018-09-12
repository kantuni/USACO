/*
ID: henrikh1
TASK: wormhole
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairings(vector<int> nums) {
  vector<vector<int>> ans;
  if (nums.size() == 2) {
    return {nums};
  }
  for (int i = 1; i < nums.size(); i++) {
    vector<int> tmp(nums);
    swap(tmp[1], tmp[i]);
    vector<int> sub(tmp.begin() + 2, tmp.end());
    vector<vector<int>> rest = pairings(sub);
    for (int j = 0; j < rest.size(); j++) {
      vector<int> comb;
      comb.push_back(tmp[0]);
      comb.push_back(tmp[1]);
      comb.insert(comb.end(), rest[j].begin(), rest[j].end());
      ans.push_back(comb);
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
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    nums[i] = i;
  }
  int ans = 0;
  vector<vector<int>> combs = pairings(nums);
  for (int i = 0; i < combs.size(); i++) {
    vector<int> redir(n);
    for (int j = 0; j < n; j += 2) {
      redir[combs[i][j]] = combs[i][j + 1];
      redir[combs[i][j + 1]] = combs[i][j];
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
  fout << ans << "\n";
  return 0;
}
