/*
ID: henrikh1
TASK: kimbits
LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("kimbits.in");
  ofstream fout("kimbits.out");
  long long N, L, I;
  fin >> N >> L >> I;
  auto cnt = 0;
  string s;
  if (L == N) {
    s = bitset<32>(I - 1).to_string();
  } else if (I < (1LL << L)) {
    for (auto i = 0; i < (1LL << L) + 1; i++) {
      bitset<32> b(i);
      if (b.count() > L) {
        continue;
      }
      cnt++;
      if (cnt == I) {
        s = b.to_string();
        break;
      }
    }
  } else {
    cnt = 1LL << L;
    for (auto i = 1LL << L; i < (1LL << N) + 1; i++) {
      bitset<32> b(i);
      if (b.count() > L) {
        continue;
      }
      cnt++;
      if (cnt == I) {
        s = b.to_string();
        break;
      }
    }
  }
  fout << s.substr(s.size() - N) << "\n";
  return 0;
}
