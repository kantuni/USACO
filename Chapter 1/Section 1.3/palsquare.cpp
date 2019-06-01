/*
ID: henrikh1
TASK: palsquare
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
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");
  int b;
  fin >> b;
  for (int n = 1; n < 301; n++) {
    string nb = convert(n, b);
    string nsb = convert(n * n, b);
    if (palindrome(nsb)) {
      fout << nb << " " << nsb << endl;
    }
  }
  return 0;
}
