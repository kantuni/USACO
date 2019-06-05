/*
ID: henrikh1
TASK: lamps
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> on, off;
set<string> ans;

string click(string s, int btn) {
  if (btn == 0) {
    for (int i = 0; i < s.size(); i++) {
      s[i] = (s[i] == '0') ? '1' : '0';
    }
  } else if (btn == 1) {
    for (int i = 1; i < s.size(); i += 2) {
      s[i] = (s[i] == '0') ? '1' : '0';
    }
  } else if (btn == 2) {
    for (int i = 0; i < s.size(); i += 2) {
      s[i] = (s[i] == '0') ? '1' : '0';
    }
  } else {
    for (int i = 0; i < s.size(); i += 3) {
      s[i] = (s[i] == '0') ? '1' : '0';
    }
  }
  return s;
}

void solve(string s, int n) {
  if (n == 0) {
    for (auto lid: on) {
      if (s[lid - 1] != '1') {
        return;
      }
    }
    for (auto lid: off) {
      if (s[lid - 1] != '0') {
        return;
      }
    }
    ans.insert(s);
  } else {
    for (int i = 0; i < 4; i++) {
      solve(click(s, i), n - 1);
    }
  }
}

int main() {
  ifstream fin("lamps.in");
  ofstream fout("lamps.out");
  int n, c;
  fin >> n >> c;
  while (true) {
    int lid;
    fin >> lid;
    if (lid == -1) {
      break;
    }
    on.push_back(lid);
  }
  while (true) {
    int lid;
    fin >> lid;
    if (lid == -1) {
      break;
    }
    off.push_back(lid);
  }
  string start = string(n, '1');
  solve(start, c);
  if (ans.size() == 0) {
    fout << "IMPOSSIBLE" << endl;
  } else {
    for (auto val: ans) {
      fout << val << endl; 
    }
  }
  return 0;
}
