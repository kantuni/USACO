/*
ID: henrikh1
TASK: subset
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("subset.in");
  ofstream fout("subset.out");
  int n;
  fin >> n;
  int sum = n * (n + 1) / 2;
  long long ans = 0;
  if (sum % 2 == 0) {
    int target = sum / 2;
    vector<long long> memo(target + 1);
    memo[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = target; j >= i; j--) {
        memo[j] += memo[j - i];
      }
    }
    ans = memo[target] / 2;
  }
  fout << ans << endl;
  return 0;
}
