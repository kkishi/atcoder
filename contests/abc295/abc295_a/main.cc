#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  set<string> st = {"and", "not", "that", "the", "you"};
  rep(n) {
    strings(s);
    if (st.count(s)) return true;
  }
  return false;
}

void Main() { wt(Solve()); }
