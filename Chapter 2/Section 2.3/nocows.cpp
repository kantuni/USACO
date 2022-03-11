/*
ID: henrikh1
TASK: nocows
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

const int P = 9901;
const int N = 200;
const int K = 100;
long long memo[N][K];

long long solve(long long n, long long k);
long long remember(long long n, long long k);

long long min_n(long long k) {
  return 2 * k - 1;
}

long long max_n(long long k) {
  return (1LL << k) - 1;
}

long long solve(long long n, long long k) {
  bool c1 = n % 2 == 0;
  bool c2 = n < min_n(k);
  if (c1 or c2) {
    return 0;
  }
  if (n == max_n(k)) {
    return 1;
  }
  long long ans = 0;
  for (long long i = 1; n - 2 * i > 0; i++) {
    long long l = n - 2 * i;
    long long r = n - 1 - l;
    for (long long j = 1; j < k - 1; j++) {
      long long p1 = remember(l, k - 1) * remember(r, j) % P;
      long long p2 = remember(l, j) * remember(r, k - 1) % P;
      ans = (ans + p1 + p2) % P;
    }
    long long p3 = remember(l, k - 1) * remember(r, k - 1) % P;
    ans = (ans + p3) % P;
  }
  return ans;
}

long long remember(long long n, long long k) {
  if (memo[n][k] == -1) {
    memo[n][k] = solve(n, k) % P;
  }
  return memo[n][k];
}

int main() {
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");
  memset(memo, -1, sizeof memo);
  long long n, k;
  fin >> n >> k;
  long long ans = solve(n, k);
  fout << ans << endl;
  return 0;
}
