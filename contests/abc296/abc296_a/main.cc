#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  strings(s);
  rep(i, n - 1) if (s[i] == s[i + 1]) return false;
  return true;
}

void Main() { wt(Solve()); }
