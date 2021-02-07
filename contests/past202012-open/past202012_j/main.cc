#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(x);
  --x;
  V<int> l(sz(s), -1);
  rep(i, sz(s)) {
    int p = i == 0 ? 0 : l[i - 1];
    if (isdigit(s[i])) {
      l[i] = p * (s[i] - '0' + 1);
    } else {
      l[i] = p + 1;
    }
    if (l[i] > x) break;
  }
  rrep(i, sz(s)) {
    if (l[i] == -1) continue;
    if (isdigit(s[i])) {
      x %= l[i - 1];
    } else if (l[i] == x + 1) {
      wt(s[i]);
      return;
    }
  }
}
