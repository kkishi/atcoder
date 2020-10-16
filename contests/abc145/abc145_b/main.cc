#include <bits/stdc++.h>

#include "atcoder.h"

bool ok() {
  ints(n);
  strings(s);
  if (n % 2) return false;
  rep(i, n / 2) if (s[i] != s[n / 2 + i]) return false;
  return true;
}

void Main() { wt(ok()); }
