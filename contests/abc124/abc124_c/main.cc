#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int solve(const string& s, int c) {
  int ret = 0;
  rep(i, s.size()) if ((s[i] - '0') != ((i + c) % 2))++ ret;
  return ret;
}

int main() {
  rd(string, s);
  wt(min(solve(s, 0), solve(s, 1)));
}
