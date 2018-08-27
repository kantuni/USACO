/*
ID: henrikh1
TASK: ride
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("ride.in");
  ofstream fout("ride.out");
  string group, comet;
  fin >> group >> comet;
  int gnum = 1, cnum = 1;
  for (int i = 0; i < group.size(); i++) {
    gnum *= group[i] - 'A' + 1;
  }
  for (int i = 0; i < comet.size(); i++) {
    cnum *= comet[i] - 'A' + 1;
  }
  if (gnum % 47 == cnum % 47) {
    fout << "GO\n";
  } else {
    fout << "STAY\n";
  }
  return 0;
}
