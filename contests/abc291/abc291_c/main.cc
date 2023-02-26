#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  strings(s);
  int x = 0, y = 0;
  set<pair<int, int>> st;
  auto check = [&]() { return st.insert({x, y}).second; };
  check();
  each(e, s) {
    if (e == 'R') ++x;
    if (e == 'L') --x;
    if (e == 'U') ++y;
    if (e == 'D') --y;
    if (!check()) return true;
  }
  return false;
}

void Main() { wt(Solve()); }
