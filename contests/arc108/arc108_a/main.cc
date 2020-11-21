#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(s, p);
  bool ok = false;
  for (int n = 0; n <= s && n * n <= p; ++n) {
    if (n * (s - n) == p) {
      ok = true;
    }
  }
  wt(ok);
}
