/*
ID: henrikh1
TASK: preface
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

string r[] = {"I", "V", "X", "L", "C", "D", "M"};
string r1[] = {"I", "X", "C", "M"};
string r5[] = {"V", "L", "D"};

string toroman(int n) {
  string res;
  int p = 0;
  while (n > 0) {
    int last = n % 10;
    if (last < 4) {
      while (last > 0) {
        res = r1[p] + res;
        last--;
      }
    } else if (last == 4) {
      res = r1[p] + r5[p] + res;
    } else if (last < 9) {
      while (last > 5) {
        res = r1[p] + res;
        last--;
      }
      res = r5[p] + res;
    } else if (last == 9) {
      res = r1[p] + r1[p + 1] + res;
    }
    n /= 10;
    p++;
  }
  return res;
}

int main() {
  ifstream fin("preface.in");
  ofstream fout("preface.out");
  int n;
  fin >> n;
  map<char, int> ans;
  for (int i = 1; i <= n; i++) {
    string roman = toroman(i);
    for (auto l: roman) {
      ans[l]++;
    }
  }
  for (int i = 0; i < 7; i++) {
    if (ans[r[i][0]] != 0) {
      fout << r[i] << " " << ans[r[i][0]] << endl;
    }
  }
  return 0;
}
