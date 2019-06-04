/*
ID: henrikh1
TASK: runround
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

bool runaround(string num) {
  set<char> digits;
  int i = 0;
  while (digits.size() != num.size() or i != 0) {
    if (num[i] == '0') {
      return false;
    }
    if (digits.count(num[i]) > 0) {
      return false;
    }
    digits.insert(num[i]);
    int skip = num[i] - '0';
    i = (i + skip) % num.size();
  }
  return true;
}

int main() {
  ifstream fin("runround.in");
  ofstream fout("runround.out");
  unsigned long long m, ans;
  fin >> m;
  ans = m + 1;
  while (true) {
    string num = to_string(ans);
    if (runaround(num)) {
      break;
    }
    ans++;
  }
  fout << ans << endl;
  return 0;
}
