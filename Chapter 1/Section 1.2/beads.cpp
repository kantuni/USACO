/*
ID: henrikh1
TASK: beads
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int front(string s) {
  int cnt = 0;
  char color = '-';
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'w' or color == s[i]) {
      cnt++;
    } else if (color == '-') {
      color = s[i];
      cnt++;
    } else {
      break;
    }
  }
  return cnt;
}

int back(string s) {
  int cnt = 0;
  char color = '-';
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == 'w' or color == s[i]) {
      cnt++;
    } else if (color == '-') {
      color = s[i];
      cnt++;
    } else {
      break;
    }
  }
  return cnt;
}

int main() {
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  int n;
  fin >> n;
  string s;
  fin >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string cut;
    for (int j = i; j < n + i; j++) {
      cut += string(1, s[j % n]);
    }
    int beads = front(cut) + back(cut);
    ans = max(ans, min(beads, n));
  }
  fout << ans << endl;
  return 0;
}
