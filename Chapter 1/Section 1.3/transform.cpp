/*
ID: henrikh1
TASK: transform
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

vvc transform(vvc A, int t) {
  vvc T(A);
  for (int r = 0; r < A.size(); r++) {
    for (int c = 0; c < A.size(); c++) {
      int rr, rc;
      if (t == 1) {
        rr = A.size() - 1 - c;
        rc = r;
      } else if (t == 2) {
        rr = A.size() - 1 - r;
        rc = A.size() - 1 - c;
      } else if (t == 3) {
        rr = c;
        rc = A.size() - 1 - r;
      } else if (t == 4) {
        rr = r;
        rc = A.size() - 1 - c; 
      }
      T[r][c] = A[rr][rc];
    }
  }
  return T;
}

int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");
  int n;
  fin >> n;
  vvc A(n, vc(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      fin >> A[r][c];
    }
  }
  vvc B(n, vc(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      fin >> B[r][c];
    }
  }
  vvc T1 = transform(A, 1);
  vvc T2 = transform(A, 2);
  vvc T3 = transform(A, 3);
  vvc T4 = transform(A, 4);
  vvc T5 = transform(T4, 1);
  vvc T6 = transform(T4, 2);
  vvc T7 = transform(T4, 3);
  int ans;
  if (B == T1) {
    ans = 1;
  } else if (B == T2) {
    ans = 2;
  } else if (B == T3) {
    ans = 3;
  } else if (B == T4) {
    ans = 4;
  } else if (B == T5 or B == T6 or B == T7) {
    ans = 5;
  } else if (B == A) {
    ans = 6;
  } else {
    ans = 7;
  }
  fout << ans << "\n";
  return 0;
}
