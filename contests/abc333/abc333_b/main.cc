#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  auto f = [&](const string& s) {
    int d = abs(s[0] - s[1]);
    return min(d, 5 - d);
  };
  wt(f(s) == f(t));
}
