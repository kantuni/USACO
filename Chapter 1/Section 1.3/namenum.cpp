/*
ID: henrikh1
TASK: namenum
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("namenum.in");
  ofstream fout("namenum.out");
  string num;
  fin >> num;
  ifstream din("dict.txt");
  vector<string> names;
  string name;
  while (getline(din, name)) {
    names.push_back(name);
  }
  map<char, char> memo;
  memo['A'] = memo['B'] = memo['C'] = '2';
  memo['D'] = memo['E'] = memo['F'] = '3';
  memo['G'] = memo['H'] = memo['I'] = '4';
  memo['J'] = memo['K'] = memo['L'] = '5';
  memo['M'] = memo['N'] = memo['O'] = '6';
  memo['P'] = memo['R'] = memo['S'] = '7';
  memo['T'] = memo['U'] = memo['V'] = '8';
  memo['W'] = memo['X'] = memo['Y'] = '9';
  bool nonames = true;
  for (string name: names) {
    if (name.size() == num.size()) {
      bool valid = true;
      for (int i = 0; i < name.size(); i++) {
        if (memo[name[i]] != num[i]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        nonames = false;
        fout << name << endl;
      }
    }
  }
  if (nonames) {
    fout << "NONE" << endl;
  }
  return 0;
}
