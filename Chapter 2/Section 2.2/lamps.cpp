/*
ID: henrikh1
TASK: lamps
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

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

int main() {
  ifstream fin("lamps.in");
  ofstream fout("lamps.out");
  int n, c;
  fin >> n >> c;
  vector<int> on;
  while (true) {
    int id;
    fin >> id;
    if (id == -1) {
      break;
    }
    on.push_back(id);
  }
  vector<int> off;
  while (true) {
    int id;
    fin >> id;
    if (id == -1) {
      break;
    }
    off.push_back(id);
  }
  string start = string(n, '1');
  set<string> all;
  all.insert(start); 
  if (c > 0) {
    all.insert(click(start, 0));
    all.insert(click(start, 1));
    all.insert(click(start, 2));
    all.insert(click(start, 3));
  }
  if (c > 1) {
    all.insert(click(click(start, 0), 3));
    all.insert(click(click(start, 1), 3));
    all.insert(click(click(start, 2), 3));
  }
  vector<string> ans;
  for (auto conf: all) {
    bool ok = true;
    for (auto id: on) {
      if (conf[id - 1] != '1') {
        ok = false;
        break;
      }
    }
    for (auto id: off) {
      if (conf[id - 1] != '0') {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans.push_back(conf);
    }
  }
  if (ans.size() == 0) {
    fout << "IMPOSSIBLE" << endl;
  } else {
    for (auto val: ans) {
      fout << val << endl;
    }
  }
  return 0;
}
