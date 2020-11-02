#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(s);
  set<int> seen;
  for (int i = 1; i <= 1000000; ++i) {
    if (!seen.insert(s).second) {
      wt(i);
      return;
    }
    s = (s & 1) ? (s * 3 + 1) : (s / 2);
  }
}
