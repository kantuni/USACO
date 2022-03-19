/*
ID: henrikh1
TASK: money
LANG: C++14
*/

// WA
#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int last);
long long remember(int n, int last);

vector<int> denoms;
map<int, map<int, long long>> memo;

long long solve(int n, int last) {
  if (n < 2) {
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
  if (memo.count(n) == 0 or memo[n].count(last) == 0) {
    memo[n][last] = solve(n, last);
  }
  return memo[n][last];
}

int main() {
  ifstream fin("money.in");
  ofstream fout("money.out");
  int V, N;
  cin >> V >> N;
  denoms.assign(V, 0);
  for (int i = 0; i < denoms.size(); i++) {
    cin >> denoms[i];
  }
  sort(denoms.begin(), denoms.end());
  long long ans = solve(N, V - 1);
  cout << ans << endl;
  return 0;
}
