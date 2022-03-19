/*
ID: henrikh1
TASK: money
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;
const int MAX_V = 25;

long long solve(int n, int last);
long long remember(int n, int last);

vector<int> denoms;
long long memo[MAX_N][MAX_V];

long long solve(int n, int last) {
  if (n == 0) {
    return 1;
  }
  long long ans = 0;
  for (int i = 0; i <= last; i++) {
    if (n - denoms[i] < 0) {
      break;
    }
    ans += remember(n - denoms[i], i);
  }
  return ans;
}

long long remember(int n, int last) {
  if (memo[n][last] == -1) {
    memo[n][last] = solve(n, last);
  }
  return memo[n][last];
}

int main() {
  ifstream fin("money.in");
  ofstream fout("money.out");
  int V, N;
  fin >> V >> N;
  denoms.assign(V, 0);
  for (int i = 0; i < denoms.size(); i++) {
    fin >> denoms[i];
  }
  sort(denoms.begin(), denoms.end());
  memset(memo, -1, sizeof memo);
  long long ans = solve(N, V - 1);
  fout << ans << endl;
  return 0;
}
