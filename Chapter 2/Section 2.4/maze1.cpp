/*
ID: henrikh1
TASK: maze1
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

char dr[] = {0, 0, 1, -1};
char dc[] = {1, -1, 0, 0};

int main() {
  ifstream fin("maze1.in");
  ofstream fout("maze1.out");
  int w, h;
  fin >> w >> h;
  fin.ignore();
  char M[2 * h + 1][2 * w + 1];
  vector<pair<int, int>> exits;
  for (int r = 0; r < 2 * h + 1; r++) {
    string row;
    getline(fin, row);
    for (int c = 0; c < 2 * w + 1; c++) {
      M[r][c] = row[c];
      if (M[r][c] != ' ') {
        M[r][c] = '*';
      } else if (r == 0 or c == 0 or r == 2 * h or c == 2 * w) {
        exits.push_back({r, c});
      }
    }
  }
  // BFS for Exit #1
  queue<tuple<int, int, int>> q1;
  map<pair<int, int>, int> d1;
  auto [re1, ce1] = exits[0];
  q1.push({re1, ce1, 1});
  d1[{re1, ce1}] = 1;
  while (!q1.empty()) {
    auto [r, c, d] = q1.front(); q1.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      bool rok = nr >= 0 and nr < 2 * h + 1;
      bool cok = nc >=0 and nc < 2 * w + 1;
      if (rok and cok and M[nr][nc] == ' ' and d1.count({nr, nc}) == 0) {
        q1.push({nr, nc, d + 1});
        d1[{nr, nc}] = d + 1;
      }
    }
  }
  // BFS for Exit #2
  queue<tuple<int, int, int>> q2;
  map<pair<int, int>, int> d2;
  auto [re2, ce2] = exits[1];
  q2.push({re2, ce2, 1});
  d2[{re2, ce2}] = 1;
  while (!q2.empty()) {
    auto [r, c, d] = q2.front(); q2.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      bool rok = nr >= 0 and nr < 2 * h + 1;
      bool cok = nc >=0 and nc < 2 * w + 1;
      if (rok and cok and M[nr][nc] == ' ' and d2.count({nr, nc}) == 0) {
        q2.push({nr, nc, d + 1});
        d2[{nr, nc}] = d + 1;
      }
    }
  }
  int ans = 0;
  for (auto [p, d]: d1) {
    ans = max(ans, min(d, d2[p]));
  }
  fout << ans / 2 << "\n";
  return 0;
}
