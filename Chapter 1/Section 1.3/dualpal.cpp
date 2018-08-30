/*
ID: henrikh1
TASK: dualpal
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

bool palindrome(string num) {
  for (int i = 0; i < num.size() / 2; i++) {
    if (num[i] != num[num.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

string convert(int n, int b) {
  string nb;
  while (n > 0) {
    int rem = n % b;
    if (rem < 10) {
      nb += to_string(rem);
    } else {
      nb += string(1, rem - 10 + 'A');
    }
    n /= b;
  }
  reverse(nb.begin(), nb.end());
  return nb;
}

int main() {
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");
  int n, s;
  fin >> n >> s;
  for (int i = s + 1; n > 0; i++) {
    int cnt = 0;
    for (int b = 2; b < 11; b++) {
      string num = convert(i, b);
      if (palindrome(num)) {
        cnt++;
      }
    }
    if (cnt > 1) {
      fout << i << "\n";
      n--;
    }
  }
  return 0;
}
