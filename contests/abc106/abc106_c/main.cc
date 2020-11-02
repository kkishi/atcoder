#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  rep(i, s.size()) {
    if (k == 1 || s[i] != '1') {
      wt(s[i]);
      return;
    }
    --k;
  }
}
