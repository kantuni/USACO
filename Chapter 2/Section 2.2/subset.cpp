/*
ID: henrikh1
TASK: subset
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v1, v2;
map<int, int> m1, m2;

void split(int n) {
  int mid = (n % 2 == 0) ? n / 2 : n / 2 + 1;
  for (int i = 1, j = mid + 1; j <= n; i++, j++) {
    if (i % 2 == 1) {
      v1.push_back(i);
      v2.push_back(j);
    } else {
      v1.push_back(j);
      v2.push_back(i);
    }
  }
  if (n % 2 == 1) {
    v1.push_back(n / 2 + 1);
  }
}

void subsum(vector<int>& nums, map<int, int>& memo) {
  for (int i = 1; i < pow(2, nums.size()); i++) {
    bitset<20> bin(i);
    int sum = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (bin[j] == 1) {
        sum += nums[j];
      }
    }
    memo[sum]++;
  }
}

long long solve(int n) {
  split(n);
  subsum(v1, m1);
  subsum(v2, m2);
  long long ans = 1;
  for (auto kv: m1) {
    ans += m1[kv.first] * m2[kv.first];
  }
  return ans / 2;
}

int main() {
  ifstream fin("subset.in");
  ofstream fout("subset.out");
  int n;
  fin >> n;
  int sum = n * (n + 1) / 2;
  long long ans = (sum % 2 == 0) ? solve(n) : 0;
  fout << ans << endl;
  return 0;
}
