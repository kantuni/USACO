/*
ID: henrikh1
TASK: ttwo
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

char b[10][10];
set<tuple<int, int, char, int, int, char>> s;

bool valid(int r, int c) {
  bool rok = 0 <= r and r < 10;
  bool cok = 0 <= c and c < 10;
  return rok and cok and b[r][c] == '.';
}

tuple<int, int, char> tick(int r, int c, char d) {
  if (d == 'N') {
    return valid(r - 1, c) ? make_tuple(r - 1, c, 'N') : make_tuple(r, c, 'E');
  } else if (d == 'E') {
    return valid(r, c + 1) ? make_tuple(r, c + 1, 'E') : make_tuple(r, c, 'S');
  } else if (d == 'S') {
    return valid(r + 1, c) ? make_tuple(r + 1, c, 'S') : make_tuple(r, c, 'W');
  } else {
    return valid(r, c - 1) ? make_tuple(r, c - 1, 'W') : make_tuple(r, c, 'N');
  }
}

int main() {
  ifstream fin("ttwo.in");
  ofstream fout("ttwo.out");
  int rf, cf, rc, cc;
  char df = 'N', dc = 'N';
  for (int r = 0; r < 10; r++) {
    for (int c = 0; c < 10; c++) {
      fin >> b[r][c];
      if (b[r][c] == 'F') {
        rf = r, cf = c;
        b[r][c] = '.';
      } else if (b[r][c] == 'C') {
        rc = r, cc = c;
        b[r][c] = '.';
      }
    }
  }
  s.insert({rf, cf, df, rc, cc, dc});
  while (true) {
    tie(rf, cf, df) = tick(rf, cf, df);
    tie(rc, cc, dc) = tick(rc, cc, dc);
    if (rf == rc and cf == cc) {
      fout << s.size() << "\n";
      break;
    }
    auto nxt = make_tuple(rf, cf, df, rc, cc, dc);
    if (s.count(nxt) == 1) {
      fout << 0 << "\n";
      break;
    }
    s.insert(nxt);
  }
  return 0;
}
