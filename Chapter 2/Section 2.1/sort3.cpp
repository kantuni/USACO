/*
ID: henrikh1
TASK: sort3
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  //ifstream fin("sort3.in");
  //ofstream fout("sort3.out");
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(a);
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n"; 
  return 0;
}
