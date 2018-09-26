/*
ID: henrikh1
TASK: pprime
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

bool prime(int n, int a, int b) {
  if (n < a or n > b) {
    return false;
  }
  for (int i = 2; i < sqrt(1.0 * n) + 1; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ifstream fin("pprime.in");
  ofstream fout("pprime.out");
  int a, b;
  fin >> a >> b;
  vector<int> palindromes;
  for (int d1 = 1; d1 < 10; d1 += 2) {
    int p = d1;
    palindromes.push_back(p);
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    int p = 10 * d1 + d1;
    palindromes.push_back(p);
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      int p = 100 * d1 + 10 * d2 + d1;
      palindromes.push_back(p);
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      int p = 1000 * d1 + 100 * d2 + 10 * d2 + d1;
      palindromes.push_back(p);
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      for (int d3 = 0; d3 < 10; d3++) {
        int p = 10000 * d1 + 1000 * d2 + 100 * d3 +
                10 * d2 + d1;
        palindromes.push_back(p);
      }
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      for (int d3 = 0; d3 < 10; d3++) {
        int p = 100000 * d1 + 10000 * d2 + 1000 * d3 +
                100 * d3 + 10 * d2 + d1;
        palindromes.push_back(p);
      }
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      for (int d3 = 0; d3 < 10; d3++) {
        for (int d4 = 0; d4 < 10; d4++) {
          int p = 1000000 * d1 + 100000 * d2 + 10000 * d3 +
                  1000 * d4 + 100 * d3 + 10 * d2 + d1;
          palindromes.push_back(p);
        }
      }
    }
  }
  for (auto palindrome: palindromes) {
    if (prime(palindrome, a, b)) {
      fout << palindrome << "\n";
    }
  }
  return 0;
}
