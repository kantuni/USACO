/*
ID: henrikh1
TASK: maze1
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int w, h;
vector<vector<char>> M;
char dr[] = {0, 0, 1, -1};
char dc[] = {1, -1, 0, 0};

vector<vector<int>> bfs(int er, int ec) {
  vector<vector<int>> D(2 * h + 1, vector<int>(2 * w + 1));
  queue<tuple<int, int, int>> q;
  q.push({er, ec, 1});
  while (!q.empty()) {
    auto [r, c, d] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      bool rok = nr >= 0 and nr < 2 * h + 1;
      bool cok = nc >=0 and nc < 2 * w + 1;
      if (rok and cok and M[nr][nc] == ' ' and D[nr][nc] == 0) {
        q.push({nr, nc, d + 1});
        D[nr][nc] = d + 1;
      }
    }
  }
  return D;
}

int main() {
  ifstream fin("maze1.in");
  ofstream fout("maze1.out");
  fin >> w >> h;
  fin.ignore();
  M.assign(2 * h + 1, vector<char>(2 * w + 1));
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
  auto [er1, ec1] = exits[0];
  auto [er2, ec2] = exits[1];
  auto D1 = bfs(er1, ec1);
  auto D2 = bfs(er2, ec2);
  int ans = 0;
  for (int r = 0; r < 2 * h + 1; r++) {
    for (int c = 0; c < 2 * w + 1; c++) {
      ans = max(ans, min(D1[r][c], D2[r][c]));
    }
  }
  fout << ans / 2 << "\n";
  return 0;
}
