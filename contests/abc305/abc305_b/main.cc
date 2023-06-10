#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> d = {0, 3, 1, 4, 1, 5, 9};
  rep(i, sz(d) - 1) d[i + 1] += d[i];
  rd(char, p, q);
  wt(abs(d[p - 'A'] - d[q - 'A']));
}
