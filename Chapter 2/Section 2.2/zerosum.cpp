/*
ID: henrikh1
TASK: zerosum
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int nextToken(string& exp, int& i) {
  int token = 0;
  for (int j = i + 1; j < exp.size(); j++) {
    if (exp[j] == ' ') continue;
    if (exp[j] == '+' or exp[j] == '-') {
      break;
    }
    token = 10 * token + (exp[j] - '0');
    i = j;
  }
  return token;
}

int eval(string& exp) {
  int ans = 1;
  for (int i = 1; i < exp.size(); i++) {
    if (exp[i] == ' ') {
      ans = 10 * ans + (exp[i + 1] - '0');
    } else if (exp[i] == '+') {
      ans += nextToken(exp, i);
    } else if (exp[i] == '-') {
      ans -= nextToken(exp, i);
    }
  }
  return ans;
}

void dfs(string s, int i, int n) {
  if (i == n) {
    if (eval(s) == 0) {
      fout << s << endl;
    }
    return;
  }
  string nxt = to_string(i + 1);
  dfs(s + " " + nxt, i + 1, n);
  dfs(s + "+" + nxt, i + 1, n);
  dfs(s + "-" + nxt, i + 1, n);
}

int main() {
  int n;
  fin >> n;
  dfs("1", 1, n);
  return 0;
}
